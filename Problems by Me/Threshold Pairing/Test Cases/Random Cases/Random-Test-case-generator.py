import random
import os

def generate_array(N, P, Q):
    """Generates various test scenarios uniformly for a given N."""
    scenario = random.choice(["random", "binary", "impossible_same", "trap_small_large", "exact_threshold"])
    
    if scenario == "impossible_same" or N < 2:
        # All elements the same, no two distinct categories exist
        val = random.randint(1, 10**9)
        return [val] * N
        
    elif scenario == "binary":
        # Only two distinct values
        val1, val2 = random.sample(range(1, 10**9 + 1), 2)
        count1 = random.randint(1, N - 1)
        return [val1] * count1 + [val2] * (N - count1)
        
    elif scenario == "trap_small_large":
        # Large frequency of small values, small frequency of huge values
        val1, val2 = random.randint(1, 10), random.randint(10**8, 10**9)
        count1 = max(1, N - random.randint(1, min(10, N - 1)))
        return [val1] * count1 + [val2] * (N - count1)
        
    elif scenario == "exact_threshold":
        # At least one element hits exactly P, another exactly Q
        arr = []
        val1, val2 = random.sample(range(1, 10**9 + 1), 2)
        if P + Q <= N:
            arr.extend([val1] * P)
            arr.extend([val2] * Q)
            while len(arr) < N:
                arr.append(random.randint(1, 10**9))
        else:
            arr = [random.randint(1, 10**9) for _ in range(N)]
        return arr
        
    else:
        # Completely random
        return [random.randint(1, 10**9) for _ in range(N)]

def generate_file(filename, T):
    """Generates a single .in file with T test cases summing N <= 2e5."""
    # Base minimum N for each test case
    Ns = [2] * T
    
    # Randomly distribute remaining N budget (max 200,000 total per file)
    remaining_budget = random.randint(0, 200000 - 2 * T)
    
    # For large T, spreading purely element-by-element is slow, so we use chunks
    for _ in range(min(remaining_budget, 5000)): 
        idx = random.randint(0, T - 1)
        chunk = random.randint(1, remaining_budget // 100 + 1)
        chunk = min(chunk, remaining_budget)
        Ns[idx] += chunk
        remaining_budget -= chunk
        if remaining_budget <= 0:
            break
            
    with open(filename, "w") as f:
        f.write(f"{T}\n")
        
        for N in Ns:
            P = random.randint(1, N)
            Q = random.randint(1, N)
            
            arr = generate_array(N, P, Q)
            random.shuffle(arr)
            
            f.write(f"{N} {P} {Q}\n")
            f.write(" ".join(map(str, arr)) + "\n")

if __name__ == "__main__":
    for i in range(1, 21):
        # Vary T from 1 up to 10,000 for different test file densities
        if i <= 5:
            T = random.randint(1, 10)         # Few cases, huge N
        elif i <= 10:
            T = random.randint(10, 100)       # Medium cases, large N
        elif i <= 15:
            T = random.randint(100, 1000)     # Many cases, medium N
        else:
            T = random.randint(1000, 10000)   # Max limit cases, small N
            
        filename = f"{i}.in"
        generate_file(filename, T)
        print(f"Generated {filename} with T = {T} (Sum of N <= 200000)")
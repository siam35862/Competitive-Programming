import os
import random

def generate_n_partition(T, max_sum=200000):
    total_sum = random.randint(T, max_sum)
    if T == 1:
        return [total_sum]
    
    cuts = sorted(random.sample(range(1, total_sum), T - 1))
    n_list = []
    prev = 0
    for cut in cuts:
        n_list.append(cut - prev)
        prev = cut
    n_list.append(total_sum - prev)
    return n_list

def generate_array_with_duplicates(N, val_min=1, val_max=10**9, dup_ratio=0.5):
    if N == 0:
        return []
    
    unique_count = max(1, int(N * (1 - dup_ratio)))
    value_pool = [random.randint(val_min, val_max) for _ in range(unique_count)]
    arr = [random.choice(value_pool) for _ in range(N)]
    return arr

def generate_test_cases():
    MAX_SUM = 200000
    current_dir = os.getcwd()
    
    for file_id in range(1, 21):
        filepath = os.path.join(current_dir, f"{file_id}.in")
        
        if file_id == 1:
            T, n_list = 1, [1]
        elif file_id == 2:
            T, n_list = 10000, [1] * 10000
        elif file_id == 3:
            T, n_list = 1, [MAX_SUM]
        else:
            T = random.randint(1, 10000)
            n_list = generate_n_partition(T, MAX_SUM)

        with open(filepath, "w") as f:
            f.write(f"{T}\n")
            for N in n_list:
                f.write(f"{N}\n")
                
                if file_id % 4 == 0:
                    arr = generate_array_with_duplicates(N, val_min=1, val_max=100, dup_ratio=0.9)
                elif file_id % 4 == 1:
                    val = random.randint(1, 10**9)
                    arr = [val] * N
                elif file_id % 4 == 2:
                    arr = generate_array_with_duplicates(N, val_min=1, val_max=10**9, dup_ratio=0.5)
                else:
                    arr = [random.randint(1, min(N, 1000)) for _ in range(N)]
                
                f.write(" ".join(map(str, arr)) + "\n")

if __name__ == "__main__":
    generate_test_cases()
import sys

N = 200000

# Phase table probed empirically from THIS libstdc++/g++ build:
# (low_size, high_size, bucket_count_active_in_that_range)
phases = [
    (1,13,13),(14,29,29),(30,59,59),(60,127,127),(128,257,257),
    (258,541,541),(542,1109,1109),(1110,2357,2357),(2358,5087,5087),
    (5088,10273,10273),(10274,20753,20753),(20754,42043,42043),
    (42044,85229,85229),(85230,172933,172933),(172934,351061,351061),
]

VAL_CAP = 10**9

result = [None]*(N+1)  # 1-indexed positions
used = set()

def next_free_multiple(P, off, start_k):
    k = start_k
    while True:
        v = P*k + off
        if v > VAL_CAP:
            return None, k
        if v not in used:
            return v, k
        k += 1

offset_counter = 1
for idx,(lo,hi,P) in enumerate(phases):
    if lo > N: break
    hi = min(hi, N)
    window = hi - lo + 1
    cap = VAL_CAP // P
    m = min(window, cap)
    off = offset_counter
    offset_counter += 1
    k = 1
    placed = 0
    pos = lo
    while placed < m and pos <= hi:
        v, k = next_free_multiple(P, off, k)
        if v is None:
            break
        used.add(v)
        result[pos] = v
        pos += 1
        k += 1
        placed += 1
    # any leftover positions in this window get filler later

# Fill remaining (unfilled) positions with arbitrary unique filler values
filler_pool_start = 1
next_filler = 1
for pos in range(1, N+1):
    if result[pos] is None:
        while next_filler in used or next_filler == 0:
            next_filler += 1
        result[pos] = next_filler
        used.add(next_filler)
        next_filler += 1

assert len(set(result[1:N+1])) == N
assert all(1 <= v <= VAL_CAP for v in result[1:N+1])

with open("8.in","w") as f:
    f.write("1\n")
    f.write(f"{N}\n")
    f.write(" ".join(str(result[i]) for i in range(1,N+1)))
    f.write("\n")

print("done, sample values:", result[1:5], "...", result[N-3:N+1])
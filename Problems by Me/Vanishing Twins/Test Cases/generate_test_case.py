import sys

T = 5
N_PER_CASE = 40000  # 5 * 40000 = 200000 total
VAL_CAP = 10**9

ALL_PHASES = [
    (1,13,13),(14,29,29),(30,59,59),(60,127,127),(128,257,257),
    (258,541,541),(542,1109,1109),(1110,2357,2357),(2358,5087,5087),
    (5088,10273,10273),(10274,20753,20753),(20754,42043,42043),
    (42044,85229,85229),(85230,172933,172933),(172934,351061,351061),
]

def build_one_case(n, case_id):
    result = [None]*(n+1)
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
    for (lo,hi,P) in ALL_PHASES:
        if lo > n:
            break
        hi = min(hi, n)
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

    next_filler = 1
    for pos in range(1, n+1):
        if result[pos] is None:
            while next_filler in used or next_filler == 0:
                next_filler += 1
            result[pos] = next_filler
            used.add(next_filler)
            next_filler += 1

    assert len(set(result[1:n+1])) == n
    assert all(1 <= v <= VAL_CAP for v in result[1:n+1])
    return result[1:n+1]

lines = [str(T)]
for case_idx in range(T):
    vals = build_one_case(N_PER_CASE, case_idx)
    lines.append(str(N_PER_CASE))
    lines.append(" ".join(map(str, vals)))

with open("in.in","w") as f:
    f.write("\n".join(lines) + "\n")

print("done, t =", T, "n per case =", N_PER_CASE)
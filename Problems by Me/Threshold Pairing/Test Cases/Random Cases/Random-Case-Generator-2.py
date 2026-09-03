import random
from pathlib import Path

random.seed(20260903)

# Regenerate 21.in ... 40.in with a hard guarantee:
# sum(N) <= 200000 for EVERY file.
#
# The previous generator selected N before knowing how much budget was
# actually left in a sufficiently strict way. This version allocates the
# complete N-budget first, then creates each test case from those N values.

MAX_TOTAL_N = 200_000
MAX_A = 10**9

T_values = [
    1, 527, 1054, 1580, 2106,
    2632, 3159, 3685, 4211, 4737,
    5264, 5790, 6316, 6842, 7369,
    7895, 8421, 8947, 9474, 10000
]

def make_arr(case_id, n):
    typ = case_id % 12

    if typ == 0:
        # Many duplicates
        return [random.randint(1, min(50, MAX_A)) for _ in range(n)]

    if typ == 1:
        # All equal
        return [random.randint(1, MAX_A)] * n

    if typ == 2:
        # All distinct
        start = random.randint(1, MAX_A - n)
        return list(range(start, start + n))

    if typ == 3:
        # Large values
        vals = [MAX_A - i for i in range(min(100, n))]
        return [random.choice(vals) for _ in range(n)]

    if typ == 4:
        # Two categories
        x, y = random.sample(range(1, MAX_A + 1), 2)
        k = random.randint(1, n - 1)
        return [x] * k + [y] * (n - k)

    if typ == 5:
        # Highly skewed
        a = n * 3 // 5
        b = n // 4
        c = n - a - b
        return [1] * a + [MAX_A] * b + [2] * c

    if typ == 6:
        # Random wide range
        return [random.randint(1, MAX_A) for _ in range(n)]

    if typ == 7:
        # Many categories with small frequencies
        arr = []
        v = 1
        while len(arr) < n:
            f = random.randint(1, min(8, n - len(arr)))
            arr.extend([v] * f)
            v += 1
        return arr

    if typ == 8:
        # Threshold-boundary-friendly distribution
        k = max(1, min(20, n))
        return [random.randint(1, k) for _ in range(n)]

    if typ == 9:
        # Values near 1e9 and 1
        vals = [1, 2, 3, MAX_A, MAX_A-1, MAX_A-2]
        return [random.choice(vals) for _ in range(n)]

    if typ == 10:
        # Medium number of categories
        k = min(n, random.randint(2, 100))
        return [random.randint(1, k) for _ in range(n)]

    # Alternating structured values
    vals = [1, MAX_A, 2, MAX_A-1, 3, MAX_A-2]
    return [vals[i % len(vals)] for i in range(n)]


def make_pq(case_id, n):
    typ = case_id % 10

    if typ == 0:
        return n, n

    if typ == 1:
        return 1, n

    if typ == 2:
        return n, 1

    if typ == 3:
        return max(1, n // 2), max(1, n // 2)

    if typ == 4:
        return max(1, n // 3), max(1, n // 5)

    if typ == 5:
        return max(1, n // 5), max(1, n // 3)

    if typ == 6:
        return random.randint(1, n), random.randint(1, n)

    if typ == 7:
        p = random.randint(1, n)
        q = random.randint(1, n)
        while q == p and n > 1:
            q = random.randint(1, n)
        return p, q

    if typ == 8:
        return max(1, n - 1), max(1, n - 1)

    return max(1, n // 10), max(1, n // 20)


def allocate_n(T, total_limit):
    """Allocate positive N >= 2 values whose exact sum <= total_limit."""
    # Start every test case at 2.
    total = 2 * T

    if total > total_limit:
        raise ValueError("T is too large for the N constraint")

    remaining = total_limit - total
    ns = [2] * T

    # Spread remaining N pseudo-randomly, but NEVER exceed the limit.
    order = list(range(T))
    random.shuffle(order)

    for i in order:
        if remaining == 0:
            break

        # Give each case a random chunk, capped at 5000.
        add = random.randint(0, min(5000, remaining))
        ns[i] += add
        remaining -= add

    # Put any leftover into random cases.
    while remaining:
        i = random.randrange(T)
        add = min(remaining, 5000)
        ns[i] += add
        remaining -= add

    assert sum(ns) == total_limit
    assert min(ns) >= 2
    assert max(ns) <= MAX_TOTAL_N
    return ns


created = []

for file_number, T in zip(range(21, 41), T_values):
    ns = allocate_n(T, MAX_TOTAL_N)

    lines = [str(T)]

    for i, n in enumerate(ns):
        p, q = make_pq(i + file_number, n)
        arr = make_arr(i + file_number, n)

        assert len(arr) == n
        assert 2 <= n <= 200_000
        assert 1 <= p <= n
        assert 1 <= q <= n
        assert all(1 <= x <= MAX_A for x in arr)

        lines.append(f"{n} {p} {q}")
        lines.append(" ".join(map(str, arr)))

    path = Path(f"{file_number}.in")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")

    # Verify the actual written file independently.
    with path.open("r", encoding="utf-8") as f:
        actual_T = int(f.readline())
        actual_sum_n = 0
        for _ in range(actual_T):
            n, p, q = map(int, f.readline().split())
            actual_sum_n += n
            # Consume the array line.
            a = list(map(int, f.readline().split()))
            assert len(a) == n

    assert actual_T == T
    assert actual_sum_n <= MAX_TOTAL_N

    created.append((file_number, T, actual_sum_n, str(path)))

print("Regenerated and independently verified:")
for x in created:
    print(f"{x[0]}.in : T={x[1]:5d}, sum(N)={x[2]:6d}")

print("\nAll 20 files satisfy sum(N) <= 200000.")

import random
from pathlib import Path

random.seed(20260904)
MAX_N = 200_000

T_values = [100, 500, 1000, 1500, 2000, 3000, 4000, 6000, 8000, 10000]

def allocate_n(T):
    # Keep every test case reasonably large so that every case can contain
    # many P/Q-eligible categories.
    minimum_n = 10
    assert minimum_n * T <= MAX_N

    ns = [minimum_n] * T
    remaining = MAX_N - minimum_n * T

    while remaining:
        i = random.randrange(T)
        add = min(remaining, random.randint(1, 3000))
        ns[i] += add
        remaining -= add

    assert sum(ns) == MAX_N
    return ns


def make_case(case_id, n):
    # Choose thresholds so that 5 categories occurring P times and
    # 5 categories occurring Q times always fit.
    if n <= 20:
        p = q = 1
    else:
        # p+q <= roughly n/10, so 5P + 5Q <= n.
        p = max(1, n // (20 + case_id % 7))
        q = max(1, n // (25 + case_id % 7))

        # Explicitly guarantee room for 5 P-groups + 5 Q-groups.
        while 5 * p + 5 * q > n:
            p = max(1, p - 1)
            q = max(1, q - 1)

    num_p = 5
    num_q = 5

    arr = []
    used = set()

    # Five distinct P-frequency categories.
    base_p = 900_000_000 - (case_id % 100_000)
    for j in range(num_p):
        x = base_p - j * 10_000
        used.add(x)
        arr.extend([x] * p)

    # Five distinct Q-frequency categories.
    base_q = 800_000_000 - (case_id % 100_000)
    for j in range(num_q):
        x = base_q - j * 10_000
        used.add(x)
        arr.extend([x] * q)

    # Fill the rest with additional categories.
    # Their frequency is < min(P,Q), unless P=Q=1; in that case
    # use frequency 1, creating EVEN MORE eligible categories.
    remaining = n - len(arr)
    noise_freq = max(1, min(p, q) - 1)

    x = 1 + (case_id % 500_000)

    while remaining:
        while x in used:
            x += 1

        f = min(remaining, random.randint(1, noise_freq))
        used.add(x)
        arr.extend([x] * f)
        remaining -= f
        x += 1

    random.shuffle(arr)

    return n, p, q, arr


for file_no, T in zip(range(41, 51), T_values):
    ns = allocate_n(T)
    lines = [str(T)]

    for i, n in enumerate(ns):
        n, p, q, arr = make_case(file_no * 100_000 + i, n)

        assert len(arr) == n
        assert 2 <= n <= 200_000
        assert 1 <= p <= n and 1 <= q <= n
        assert all(1 <= x <= 10**9 for x in arr)

        # Verify multiple choices exist for BOTH thresholds.
        freq = {}
        for x in arr:
            freq[x] = freq.get(x, 0) + 1

        p_candidates = [x for x, f in freq.items() if f >= p]
        q_candidates = [x for x, f in freq.items() if f >= q]

        assert len(p_candidates) >= 2
        assert len(q_candidates) >= 2

        lines.append(f"{n} {p} {q}")
        lines.append(" ".join(map(str, arr)))

    path = Path(f"{file_no}.in")
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")

    # Read back and verify the complete file.
    total_n = 0
    with path.open("r", encoding="utf-8") as f:
        assert int(f.readline()) == T

        for _ in range(T):
            n2, p2, q2 = map(int, f.readline().split())
            a2 = list(map(int, f.readline().split()))

            assert len(a2) == n2
            assert 2 <= n2 <= 200_000
            assert 1 <= p2 <= n2 and 1 <= q2 <= n2

            freq2 = {}
            for x in a2:
                freq2[x] = freq2.get(x, 0) + 1

            assert sum(f >= p2 for f in freq2.values()) >= 2
            assert sum(f >= q2 for f in freq2.values()) >= 2

            total_n += n2

    assert total_n == 200_000

    print(
        f"{file_no}.in : T={T:5d}, sum(N)={total_n:6d}, "
        f"multiple P/Q candidates = VERIFIED"
    )

print("\nSuccessfully generated and verified 41.in ... 50.in.")

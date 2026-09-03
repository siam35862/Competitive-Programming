from pathlib import Path
import random

# ============================================================
# SAVE .IN FILES IN CURRENT DIRECTORY
# ============================================================

OUT = Path(".")

# Remove old numbered .in files
for p in OUT.glob("*.in"):
    try:
        p.unlink()
    except PermissionError:
        print(f"WARNING: Cannot delete {p}")
        raise

cases = []


def add(testcases):
    """testcases = [(N, P, Q, array), ...]"""

    assert 1 <= len(testcases) <= 10_000

    total_n = 0

    for N, P, Q, A in testcases:
        assert 2 <= N <= 200_000
        assert 1 <= P <= N
        assert 1 <= Q <= N
        assert len(A) == N
        assert all(1 <= x <= 10**9 for x in A)

        total_n += N

    assert total_n <= 200_000

    cases.append(testcases)


# ============================================================
# YOUR EXISTING 35 TEST CASE GENERATION LOGIC
# ============================================================

# 1
add([
    (2, 1, 1, [1, 2])
])

# 2
add([
    (2, 1, 1, [7, 7])
])

# 3
add([
    (10, 1, 1, [42] * 10)
])

# 4
add([
    (7, 3, 2, [10, 10, 10, 20, 20, 1, 2])
])

# 5
add([
    (10, 4, 4, [11] * 4 + [99] * 4 + [1, 2])
])

# 6
add([
    (10, 6, 3, [1] * 6 + [100] * 3 + [7])
])

# 7
add([
    (12, 7, 3, [1] * 7 + [10**9] * 3 + [500, 600])
])

# 8
add([
    (12, 3, 7, [10] * 3 + [900] * 7 + [1, 2])
])

# 9
add([
    (
        20,
        2,
        2,
        [
            10, 10,
            20, 20,
            30, 30,
            40, 40,
            50, 50,
            60, 60,
            70, 70,
            80, 80,
            90,
            1, 2, 3
        ]
    )
])

# 10
arr = []

for v in range(10, 15):
    arr += [v] * 5

for v in range(20, 27):
    arr += [v] * 3

arr += [100, 101, 102, 103]

add([
    (50, 5, 3, arr)
])

# 11
add([
    (8, 4, 4, [100] * 4 + [1, 2, 3, 4])
])

# 12
add([
    (
        20,
        5,
        3,
        [100] * 5
        + [90] * 3
        + [80] * 3
        + [70] * 3
        + [60] * 2
        + [1, 2, 3, 4]
    )
])

# 13
add([
    (12, 4, 5, [100] * 3 + [90] * 4 + [80] * 5)
])

# 14
add([
    (
        15,
        5,
        3,
        [10**9] * 2
        + [500] * 5
        + [400] * 5
        + [300] * 3
    )
])

# 15
add([
    (
        20,
        4,
        4,
        [100] * 4
        + [90] * 8
        + [80] * 4
        + [70] * 4
    )
])

# 16
add([
    (
        6,
        3,
        2,
        [10**9] * 3
        + [999_999_999] * 2
        + [1]
    )
])

# 17
add([
    (200_000, 1, 1, [123456789] * 200_000)
])

# 18
add([
    (
        200_000,
        100_000,
        100_000,
        [1] * 100_000 + [10**9] * 100_000
    )
])

# 19
A = []

for v in range(1, 101):
    A += [10_000_000 + v] * 2000

add([
    (200_000, 1500, 1500, A)
])

# 20
A = []

for v in range(1, 20_001):
    A += [v] * 10

add([
    (200_000, 10, 10, A)
])

# 21
tests = []

for t in range(10_000):
    a = [1] * 10 + [1_000_000_000] * 10

    if t % 2:
        a.reverse()

    tests.append((20, 10, 10, a))

add(tests)

# 22
tests = []

for t in range(1000):

    if t % 4 == 0:
        tests.append(
            (200, 100, 100, [5] * 200)
        )

    elif t % 4 == 1:
        tests.append(
            (
                200,
                100,
                50,
                [1] * 100
                + [10**9] * 50
                + [7] * 50
            )
        )

    elif t % 4 == 2:
        tests.append(
            (
                200,
                1,
                199,
                [2] * 199
                + [10**9]
            )
        )

    else:
        tests.append(
            (
                200,
                150,
                151,
                [1] * 150
                + [2] * 50
            )
        )

add(tests)

# 23
A = list(range(1, 200_001))

add([
    (200_000, 1, 1, A)
])

# 24
A = list(range(1, 200_001))

add([
    (200_000, 2, 2, A)
])

# 25
A = []

v = 1

freqs = [
    1, 2, 3, 4, 5,
    6, 7, 8, 9, 10
] * 20

for f in freqs:
    A += [v] * f
    v += 1

while len(A) < 200_000:
    A.append(v)
    v += 1

add([
    (200_000, 7, 4, A)
])

# 26
A = []

for v in range(1, 20_001):
    A += [v] * 10

add([
    (200_000, 10, 10, A)
])

# 27
A = []

for v in range(1, 40_001):
    A += [v] * 5

add([
    (200_000, 5, 5, A)
])

# 28
add([
    (20, 20, 1, [10] * 19 + [20])
])

# 29
add([
    (20, 1, 20, [10] * 19 + [20])
])

# 30
add([
    (
        30,
        1,
        1,
        [1] * 28
        + [500_000_000]
        + [10**9]
    )
])

# 31
A = []

for v, f in [
    (10, 7),
    (20, 7),
    (30, 7),
    (40, 6),
    (50, 6),
    (60, 5),
    (70, 5),
    (80, 4),
    (90, 4),
    (100, 3)
]:
    A += [v] * f

random.Random(123456).shuffle(A)

add([
    (54, 7, 4, A)
])

# 32
add([
    (
        30,
        5,
        5,
        [1] * 5
        + [10**9] * 5
        + [2] * 5
        + [999_999_999] * 5
        + [3] * 5
        + [999_999_998] * 5
    )
])

# 33
A = []

for v in range(1, 101):
    A += [v] * 100

for v in range(101, 601):
    A += [v] * 60

for v in range(601, 1101):
    A += [v] * 100

v = 1101

while len(A) + 90 <= 200_000:
    A += [v] * 90
    v += 1

rem = 200_000 - len(A)

if rem:
    A += [v] * rem

add([
    (200_000, 100, 50, A)
])

# 34
A = []

for v in range(1, 1001):
    A += [v] * 200

add([
    (200_000, 100, 200, A)
])

# 35
A = []

for v in range(1, 101):
    A += [v] * 9

for v in range(101, 201):
    A += [v] * 10

for v in range(201, 301):
    A += [v] * 11

v = 301

while len(A) + 10 <= 200_000:
    A += [v] * 10
    v += 1

rem = 200_000 - len(A)

if rem:
    A += [v] * rem

add([
    (200_000, 10, 10, A)
])


# ============================================================
# WRITE ALL FILES
# ============================================================

print()
print("Generating files...")

for i, testcases in enumerate(cases, 1):

    filename = f"{i}.in"

    with open(filename, "w", encoding="utf-8") as f:

        f.write(f"{len(testcases)}\n")

        for N, P, Q, A in testcases:

            f.write(f"{N} {P} {Q}\n")
            f.write(" ".join(map(str, A)) + "\n")

    print(f"Created {filename}")


# ============================================================
# VERIFY ALL FILES EXIST
# ============================================================

print()
print("Checking files...")

missing = []

for i in range(1, len(cases) + 1):

    filename = Path(f"{i}.in")

    if not filename.exists():
        missing.append(filename)

if missing:
    print("ERROR: Missing files:")
    for f in missing:
        print(f"   {f}")
    raise RuntimeError("Not all files were created.")

print(f"All {len(cases)} files exist.")


# ============================================================
# VALIDATE CONTENT OF EVERY FILE
# ============================================================

print()
print("Validating files...")

for i in range(1, len(cases) + 1):

    path = Path(f"{i}.in")

    tokens = path.read_text(encoding="utf-8").split()

    it = iter(tokens)

    T = int(next(it))

    total_n = 0

    for _ in range(T):

        N = int(next(it))
        P = int(next(it))
        Q = int(next(it))

        A = [
            int(next(it))
            for _ in range(N)
        ]

        assert 2 <= N <= 200_000
        assert 1 <= P <= N
        assert 1 <= Q <= N
        assert len(A) == N
        assert all(1 <= x <= 10**9 for x in A)

        total_n += N

    assert total_n <= 200_000

    print(
        f"{i}.in OK "
        f"(T={T}, total N={total_n})"
    )


# ============================================================
# FINAL RESULT
# ============================================================

print()
print("=" * 60)
print(f"SUCCESS: {len(cases)} files generated and validated.")
print("=" * 60)
print()
print("Files:")

for i in range(1, len(cases) + 1):
    print(f"  {i}.in")
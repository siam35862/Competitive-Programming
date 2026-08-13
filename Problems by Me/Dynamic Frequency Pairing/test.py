import random

N = 100000
Q = 100000
rng = random.Random(12345)

with open("slow.in", "w") as f:
    f.write(f"{N} {Q}\n")

    # All distinct initially
    f.write(" ".join(str(i + 1) for i in range(N)) + "\n")

    for i in range(Q):
        if i % 2 == 0:
            # Update
            pos = rng.randrange(1, N + 1)
            value = 1_000_000_000 - i
            f.write(f"1 {pos} {value}\n")
        else:
            # Random range query
            l = rng.randrange(1, N + 1)
            r = rng.randrange(l, N + 1)

            length = r - l + 1

            p = rng.randrange(1, length + 1)
            q = rng.randrange(1, length + 1)

            f.write(f"2 {l} {r} {p} {q}\n")
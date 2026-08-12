t = 20
n = 50000

with open("8.in", "w") as f:
    f.write(f"{t}\n")

    for _ in range(t):
        values = []

        # Build up to the bucket count = 42043
        for i in range(1, 20754):
            values.append(i)

        # Collision attack
        # All of these hash to bucket 0 when bucket_count = 42043
        for i in range(1, n - 20753 + 1):
            values.append(42043 * i)

        # Ensure exactly n elements
        values = values[:n]

        f.write(f"{n}\n")
        f.write(" ".join(map(str, values)))
        f.write("\n")

print("Generated unordered_set_attack.txt")
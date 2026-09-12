import math

total = 0
for i in range(1, 1001):
	total += 1 / i**2

pi = math.sqrt(total * 6)
print(f"PI = {pi:.6f}")
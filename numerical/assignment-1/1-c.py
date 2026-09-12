n = int(input("Enter N: "))
k = 0
total = 0
product = 1

for i in range(1, n + 1):
	k += 1 / i
	total += k
	product *= k

print(f"Sum = {total:.6f}")
print(f"Product = {product:.6f}")
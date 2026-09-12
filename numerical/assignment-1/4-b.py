def fact(n):
	product = 1
	for i in range(1, n + 1):
		product *= i

	return product

n = int(input("Enter N: "))
print(f"{n}! = {fact(n)}")
def fibo(n):
	if n == 0:
		return []
	elif n == 1:
		return [0]

	a, b = 0, 1
	arr = [a, b]

	for i in range(n - 2):
		a, b = b, a + b
		arr.append(b)

	return arr

n = int(input("Enter N: "))
arr = fibo(n)

for i, item in enumerate(arr):
	if (i + 1) % 3 == 0:
		print(item)
	else:
		print(item, end="\t")
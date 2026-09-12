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

arr = fibo(15)
total = 0

for item in arr:
	total += item
	
print("Sum =", total)
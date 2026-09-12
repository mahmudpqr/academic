def isPrime(n):
	if n < 2:
		return False

	i = 2
	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True

i = 0
k = 2

while i < 25:
	if isPrime(k):
		print(k, end=" ")
		i += 1

	k += 1

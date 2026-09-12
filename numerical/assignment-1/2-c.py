def isPrime(n):
	if n < 2:
		return False

	i = 2
	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True

m, n = map(int, input("Enter M and N: ").split())

i = m
while i <= n:
	if isPrime(i):
		print(i, end=" ")
		
	i += 1
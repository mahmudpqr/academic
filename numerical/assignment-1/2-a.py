def isPrime(n):
	if n < 2:
		return False

	i = 2
	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True

n = int(input("Enter N: "))

if isPrime(n):
	print("Prime")
else:
	print("Not prime")
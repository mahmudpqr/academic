def isPrime(n):
	if n < 2:
		return False

	i = 2
	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True

def divSum(n):
	total = 1
	i = 2

	while i * i <= n:
		if n % i == 0:
			total += i

			if i * i != n:
				total += n // i

		i += 1
	
	return total

n = int(input("Enter N: "))

if isPrime(n):
	print("Prime")
else:
	total = divSum(n)
	print("Sum of divisors =", total)
	if total == n:
		print("Perfect")
	else:
		print("Not perfect")
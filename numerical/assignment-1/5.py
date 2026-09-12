import math

def isPrime(n):
	if n < 2:
		return False

	i = 2
	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True

def isPerfect(n):
	if n <= 1:
		return False

	divSum = 1
	i = 2

	while i * i <= n:
		if n % i == 0:
			divSum += i

			if i * i != n:
				divSum += n // i

		i += 1

	return divSum == n

n = int(input("Enter N: "))
arr = list(map(int, input("Enter N integers: ").split()))

mn = min(arr)
mx = max(arr)

posCount = 0
negCount = 0
primCount = 0
perfCount = 0

total = 0
sqSum = 0

for item in arr:
	if item > 0:
		posCount += 1
	elif item < 0:
		negCount += 1
	if isPrime(item):
		primCount += 1
	elif isPerfect(item):
		perfCount += 1

	total += item
	sqSum += item**2

mean = total / n
vari = (sqSum / n) - mean**2
devi = math.sqrt(vari)

print("Smallest =", mn)
print("Largest =", mx)
print("Positive count =", posCount)
print("Negative count =", negCount)
print("Prime count =", primCount)
print("Perfect count =", perfCount)
print("Sum of squares =", sqSum)
print(f"Mean = {mean:.2f}")
print(f"Variance = {vari:.2f}")
print(f"Standard deviation = {devi:.2f}")
import math

def fact(n):
	if n == 0:
		return 1

	return math.exp(-n) * n**n * math.sqrt(2 * math.pi * n)

n, r = map(int, input("Enter N and R: ").split())

result = fact(n) / (fact(r) * fact(n - r))
print(f"{n}C{r} = {result:.4f}")
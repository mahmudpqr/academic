import math

def f(x):
	return x * math.log10(x) - 1.2

print(f"{'i':<5}{'a':<15}{'b':<15}{'c':<15}{'f(c)':<15}")

a = 2; b = 3; tol = 0.005
fa = f(a); i = 1

while True:
	c = (a + b) / 2
	fc = f(c)

	print(f"{i:<5}{a:<15.5f}{b:<15.5f}{c:<15.5f}{fc:<15.5f}")
	i += 1

	if fc == 0 or (b - a) / 2 < tol:
		break
	elif fa * fc < 0:
		b = c
	else:
		a = c
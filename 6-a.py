import math, cmath

def solve(a, b, c):
	if a == 0:
		return None, None

	d = b**2 - 4*a*c

	if d >= 0:
		x1 = (-b + math.sqrt(d)) / (2*a)
		x2 = (-b - math.sqrt(d)) / (2*a)
	else:
		x1 = (-b + cmath.sqrt(d)) / (2*a)
		x2 = (-b - cmath.sqrt(d)) / (2*a)

	return x1, x2

a, b, c = 2, 6, 3
x1, x2 = solve(a, b, c)

if x1 == None:
	print("Cannot solve")
else:
	print(f"x1 = {x1:.4f}")
	print(f"x2 = {x2:.4f}")
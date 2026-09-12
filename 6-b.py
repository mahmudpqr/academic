def solve(a1, b1, c1, a2, b2, c2):
	d = a1*b2 - a2*b1

	if d == 0:
		return None, None

	dx = c1*b2 - c2*b1
	dy = a1*c2 - a2*c1

	x = dx / d
	y = dy / d
	
	return x, y

a1, b1, c1 = 2, 5, 9
a2, b2, c2 = 5, -2, 8

x, y = solve(a1, b1, c1, a2, b2, c2)

if x == None:
	print("Cannot solve")
else:
	print(f"x = {x:.4f}")
	print(f"y = {y:.4f}")

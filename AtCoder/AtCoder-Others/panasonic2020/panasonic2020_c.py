a, b, c = list(map(int, input().split()))
l = 4 * a * b
r = (c - a - b) * (c - a - b)
if a >= c or b >= c:
  print("No")
elif l < r:
  print("Yes")
else:
  print("No")
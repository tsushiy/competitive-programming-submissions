r, x, y = list(map(int, input().split()))
r = r * r
d = x * x + y * y
ans = d // r

if d < r:
  print(2)
  exit()
if d % r == 0 and int(ans**(1 / 2))**2 == ans:
  print((int(ans**(1 / 2))))
else:
  print((int(ans**(1 / 2)) + 1))

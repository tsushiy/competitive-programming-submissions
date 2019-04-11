d, n = map(int, input().split())
if d == 0 and n == 100:
  print(101)
elif d == 0:
  print(n)
elif d == 1 and n == 100:
  print(10100)
elif d == 2 and n == 100:
  print(1010000)
else:
  print(100**d*n)
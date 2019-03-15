while True:
  x, y = list(map(int, input().split()))
  if x==y==0:
    break
  if x>y:
    x, y = y, x
  print(x, y)
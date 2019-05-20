a, b = list(map(int, input().split()))
if a==b:
  print(0)
else:
  t = (a+b)/2
  if t%1==0:
    print(int(t))
  else:
    print("IMPOSSIBLE")
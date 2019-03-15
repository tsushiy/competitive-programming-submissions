n, a, b = list(map(int, input().split()))
i = 0
while n>0:
  if i%2==0:
    n -= min(n, a)
    if n==0:
      print("Ant")
      break
  else:
    n -= min(n, b)
    if n==0:
      print("Bug")
      break
  i+=1
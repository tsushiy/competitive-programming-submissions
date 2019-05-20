s = int(input())
t = int(s**(1/2))
if s==1:
  print(0, 0, 1, 0, 0, 1)
elif t!=1 and s==t**2:
  t1 = t**2
  print(0, 0, t, 0, 0, t)
else:
  t1 = (t+1)**2
  t += 1
  t2 = abs(s-t1)
  ans = 0
  for i in range(int(t2**(1/2)), 0, -1):
    if t2%i==0:
      ans = i
      break
  print(0, 0, t, t2//ans, ans, t)
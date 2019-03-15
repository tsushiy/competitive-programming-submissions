n, a, b = list(map(int, input().split()))
x = 0
for i in range(n):
  s, d = input().split()
  d = int(d)
  if s=="East":
    if d<=b:
      x += max(d, a)
    else:
      x += b
  else:
    if d<=b:
      x -= max(d, a)
    else:
      x -= b
if x==0:
  print(0)
elif x<0:
  print("West", -x)
else:
  print("East", x)
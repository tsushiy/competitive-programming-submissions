from math import pi
n = int(input())
r = [int(input()) for i in range(n)]
r.sort(reverse=True)
t = 0
for i in range(n):
  if i%2==0:
    t+=r[i]*r[i]
  else:
    t-=r[i]*r[i]
print(t*pi)
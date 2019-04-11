n = int(input())
a = (list(map(int, input().split())))

s = abs(a[0])
for i in range(1, n):
  s += abs(a[i]-a[i-1])
s += abs(a[-1])

for i in range(n):
  if i==0:
    t1 = 0
  else:
    t1 = a[i-1]
  if i==n-1:
    t3 = 0
  else:
    t3 = a[i+1]
  t2 = a[i]
  ans = s+abs(t3-t1)-(abs(t3-t2)+abs(t2-t1))
  print(ans)
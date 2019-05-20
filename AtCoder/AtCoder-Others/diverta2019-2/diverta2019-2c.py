n = int(input())
a = list(map(int, input().split()))
a.sort()
ps = []
ms = []

cnt = 0
ans = 0
anss = []
for e in a:
  if e<0:
    cnt += 1
    ms.append(e)
  else:
    ps.append(e)
  ans += abs(e)
if cnt==n:
  ans += a[n-1]*2
elif cnt==0:
  ans -= a[0]*2
print(ans)

if cnt==0:
  cur = a[0]
  a.remove(cur)
  for i in range(n-2):
    print(cur, a[i])
    cur = cur-a[i]
  print(a[n-2], cur)
elif cnt==n:
  cur = a[n-1]
  a.remove(cur)
  for i in range(n-1):
    print(cur, a[i])
    cur = cur-a[i]
else:
  while len(ps)>1:
    t = ps.pop()
    print(ms[0], t)
    ms[0] -= t
  while len(ms):
    t = ms.pop()
    print(ps[0], t)
    ps[0] -= t

for e in anss:
  print(*e)

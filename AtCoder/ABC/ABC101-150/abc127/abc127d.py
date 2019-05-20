n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
a.sort()
b = [list(map(int, input().split())) for i in range(m)]
b.sort(key=lambda x: x[1], reverse=True)

from bisect import bisect_left
cur = 0
ans = 0
for e in b:
  t = bisect_left(a, e[1])
  if t>=cur:
    ans += min(t-cur, e[0])*e[1]
    cur += min(t-cur, e[0])
while cur<len(a):
  ans += a[cur]
  cur += 1
print(ans)
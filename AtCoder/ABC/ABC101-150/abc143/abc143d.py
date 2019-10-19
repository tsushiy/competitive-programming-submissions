n = int(input())
l = list(map(int, input().split()))
l.sort()

from bisect import bisect_left
ans = 0
for i in range(n):
  for j in range(i+1, n):
    t = l[i]+l[j]
    idx = bisect_left(l, t)
    ans += max(0, idx-j-1)
print(ans)
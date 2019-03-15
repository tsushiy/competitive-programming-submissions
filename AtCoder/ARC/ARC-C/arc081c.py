n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
from collections import defaultdict
d = defaultdict(int)
ans, t = 0, 0
for i in range(n):
  d[a[i]] += 1
  if d[a[i]]==2:
    d[a[i]] = 0
    ans = max(ans, t*a[i])
    t = a[i]
print(ans)
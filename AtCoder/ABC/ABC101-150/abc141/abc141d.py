n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
a = [-a[i] for i in range(n)]
a.sort()
from heapq import heappush, heappop
for i in range(m):
  t = -heappop(a)
  t //= 2
  heappush(a, -t)
print(-sum(a))
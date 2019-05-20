from heapq import heappush, heappop
from collections import deque
n, m = list(map(int, input().split()))
ab = [list(map(int, input().split())) for i in range(n)]
ab = deque(sorted(ab, key=lambda x: x[0]))

ans = 0
q = []
for i in range(1, m+1):
  while len(ab) and ab[0][0]<=i:
    a, b = ab.popleft()
    heappush(q, -b)
  if len(q):
    ans += -heappop(q)
print(ans)
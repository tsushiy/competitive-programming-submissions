n = int(input())
a = list(map(int, input().split()))
from itertools import accumulate
b = list(accumulate(a))
ans = float("INF")
for i in range(n-1):
  ans = min(ans, abs(b[i]-(b[-1]-b[i])))
print(ans)
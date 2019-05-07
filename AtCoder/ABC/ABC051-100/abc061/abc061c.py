n, k = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(int)
for i in range(n):
  a, b = list(map(int, input().split()))
  d[a] += b
for ele in sorted(d.items()):
  k -= ele[1]
  if k<=0:
    print(ele[0])
    break
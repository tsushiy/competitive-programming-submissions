n, m = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(set)
for i in range(m):
  a, b = list(map(int, input().split()))
  d[a].add(b)
  d[b].add(a)
if d[1]&d[n]:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")
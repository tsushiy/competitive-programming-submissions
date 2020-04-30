n = int(input())
a = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(set)
ans = 0
for i, e in enumerate(a, start=1):
  d[i].add(e)
  if i in d[e]:
    ans += 1
print(ans)
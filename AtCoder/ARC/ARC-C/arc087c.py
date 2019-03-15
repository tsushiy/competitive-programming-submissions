n = int(input())
a = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(int)
for ele in a:
  d[ele] += 1
ans = 0
for k, v in d.items():
  if k!=v:
    t = float("INF")
    if v>k:
      t = v-k
    ans += min(t, v)
print(ans)
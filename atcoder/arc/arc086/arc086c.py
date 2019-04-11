n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(int)
for ele in a:
  d[ele] += 1
print(sum(sorted(d.values(), reverse=True)[k:]))
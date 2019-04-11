n = int(input())
a = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(int)
for ele in a:
  d[ele] += 1
  d[ele-1] += 1
  d[ele+1] += 1
print(max(d.values()))
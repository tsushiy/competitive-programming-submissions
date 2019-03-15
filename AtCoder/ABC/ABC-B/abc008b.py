n = int(input())
s = [input() for i in range(n)]
from collections import defaultdict
d = defaultdict(int)
for ele in s:
  d[ele]+=1
l = []
for k, v in d.items():
  l.append((v, k))
l.sort()
print(l[-1][1])
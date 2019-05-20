s = input()
t = input()
from collections import defaultdict
from bisect import bisect_left
d = defaultdict(list)
for i, e in enumerate(s):
  d[e].append(i)

for e in t:
  if e not in d:
    print(-1)
    exit()
cur = -1
loop = 0
for e in t:
  idxt = bisect_left(d[e], cur-loop*len(s)+1)
  if len(d[e])>idxt:
    idx = d[e][idxt]
    cur = (loop*len(s))+idx
  else:
    loop += 1
    idxt = bisect_left(d[e], cur-loop*len(s)+1)
    idx = d[e][idxt]
    cur = (loop*len(s))+idx
print(cur+1)

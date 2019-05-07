from collections import defaultdict
from bisect import bisect_left, bisect_right
n = int(input())
d = defaultdict(int)
for i in range(n):
  q = input().split()
  if q[0]=="0":
    d[q[1]] = int(q[2])
  elif q[0]=="1":
    if q[1] in d.keys():
      print(d[q[1]])
    else:
      print(0)
  elif q[0]=="2":
    if q[1] in d.keys():
      del d[q[1]]
  elif q[0]=="3":
    t = sorted(d.items())
    l = bisect_left(t, (q[1], 0))
    r = bisect_right(t, (q[2], 10**9))
    for i in range(l, r):
      print(" ".join(map(str, t[i])))
from collections import defaultdict
from bisect import bisect_left, bisect_right
n = int(input())
d = defaultdict(list)
for i in range(n):
  q = input().split()
  if q[0]=="0":
    d[q[1]].append(int(q[2]))
  elif q[0]=="1":
    for ele in d[q[1]]:
      print(ele)
  elif q[0]=="2":
    d[q[1]] = []
  elif q[0]=="3":
    t = sorted(d.items())
    l = bisect_left(t, (q[1], []))
    r = bisect_right(t, (q[2]+"a", []))
    for i in range(l, r):
      for ele in t[i][1]:
        print(t[i][0], ele)
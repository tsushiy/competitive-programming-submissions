from bisect import bisect_left, bisect_right
n = int(input())
s = set()
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    s.add(q[1])
    print(len(s))
  elif q[0]==1:
    if q[1] in s:
      print(1)
    else:
      print(0)
  elif q[0]==2:
    if q[1] in s:
      s.remove(q[1])
  else:
    t = list(sorted(s))
    l = bisect_left(t, q[1])
    r = bisect_right(t, q[2])
    for i in range(l, r):
      print(t[i])
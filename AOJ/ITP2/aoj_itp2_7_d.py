from bisect import bisect_left, bisect_right, insort_left
n = int(input())
s = []
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    insort_left(s, q[1])
    print(len(s))
  elif q[0]==1:
    l = bisect_left(s, q[1])
    r = bisect_right(s, q[1])
    print(r-l)
  elif q[0]==2:
    l = bisect_left(s, q[1])
    r = bisect_right(s, q[1])
    s = s[:l]+s[r:]
  else:
    l = bisect_left(s, q[1])
    r = bisect_right(s, q[2])
    for i in range(l, r):
      print(s[i])
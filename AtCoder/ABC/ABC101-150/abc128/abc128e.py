from bisect import bisect_left
import sys
n, Q = [int(x) for x in sys.stdin.readline().split()]
stx = [[int(x) for x in sys.stdin.readline().split()] for i in range(n)]
q = [int(sys.stdin.readline()) for i in range(Q)]
stx.sort(key=lambda x: x[2])
ans = [-1 for i in range(Q)]
skip = [-1 for i in range(Q)]

for (s, t, x) in stx:
  begin = bisect_left(q, s-x)
  end = bisect_left(q, t-x)
  while begin<end:
    if skip[begin]==-1:
      ans[begin] = x
      skip[begin] = end
      begin += 1
    else:
      begin = skip[begin]
for e in ans:
  print(e)
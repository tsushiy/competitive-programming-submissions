from collections import deque
n = int(input())
a = deque([])
for _ in range(n):
  q = list(map(int, input().split()))
  if q[0]==0:
    if q[1]==0:
      a.appendleft(q[2])
    else:
      a.append(q[2])
  elif q[0]==1:
    print(a[q[1]])
  else:
    if q[1]==0:
      a.popleft()
    else:
      a.pop()
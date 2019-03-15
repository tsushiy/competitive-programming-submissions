n = int(input())
a = [int(input()) for i in range(n)]

from collections import defaultdict
d = defaultdict(bool)
ans = 1
t = a[0]

for _ in range(n):
  if t==2:
    break
  else:
    if d[t]:
      ans = -1
      break
    else:
      d[t] = True
      t = a[t-1]
      ans += 1

print(ans)
n, m = list(map(int, input().split()))
from collections import defaultdict
d = defaultdict(list)
for i in range(m):
  a, b = list(map(int, input().split()))
  a -= 1
  b -= 1
  d[a].append(b)
  d[b].append(a)
for i in range(n):
  ans = set()
  friend = set(d[i])
  for j in d[i]:
    for e in d[j]:
      if i!=e and e not in friend:
        ans.add(e)
  print(len(ans))
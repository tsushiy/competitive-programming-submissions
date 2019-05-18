n = int(input())
s = [input() for i in range(n)]
from collections import defaultdict
t = defaultdict(int)
ans = 0
for e in s:
  t[e[0]] += 1
for v in t.values():
  if v%2:
    v1 = v//2
    v2 = v1+1
  else:
    v1 = v2 = v//2
  if v1>1:
    ans += sum(range(v1))
  if v2>1:
    ans += sum(range(v2))
print(ans)
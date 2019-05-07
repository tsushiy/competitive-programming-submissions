from collections import defaultdict
n = int(input())
d = defaultdict(bool)
ans = 0
for i in range(n):
  a = int(input())
  if d[a]:
    ans += 1
  d[a] = True
print(ans)
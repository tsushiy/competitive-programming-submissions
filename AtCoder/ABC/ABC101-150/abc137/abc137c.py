from collections import defaultdict
n = int(input())
d = defaultdict(int)
for i in range(n):
  s = "".join(sorted(input()))
  d[s] += 1

ans = 0
for v in d.values():
  if v>=2:
    ans += v*(v-1)//2
print(ans)
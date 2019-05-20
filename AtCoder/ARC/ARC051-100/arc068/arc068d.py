n = int(input())
a = list(map(int, input().split()))
from collections import Counter
c = Counter(a)
d = dict(c)
ans = 0
cnt = 0
for k, v in d.items():
  if v%2==0:
    d[k] = 2
    cnt += 1
  else:
    d[k] = 1
  ans += 1
if cnt%2==1:
  ans -= 1
print(ans)
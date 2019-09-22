n = int(input())
s = input()
from collections import Counter
c = Counter(s)
ans = 0
mod = 10**9+7
for k, v in c.items():
  if ans == 0:
    ans = v+1
  else:
    ans = (ans * (v+1)) % mod
print(ans-1)
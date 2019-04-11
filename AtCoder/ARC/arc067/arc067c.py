MOD = 10**9+7
n = int(input())
from collections import defaultdict
d = defaultdict(int)
for i in range(2, n+1):
  j = 2
  while j*j<=i:
    while i%j==0:
      i //= j
      d[j] += 1
    j += 1
  if i>1:
    d[i] += 1
ans = 1
for ele in d.values():
  ans = ans*(ele+1)%MOD
print(ans)
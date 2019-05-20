n, k = map(int, input().split())
a = list(map(int, input().split()))

import math
ans = 0
if len(a)<=k:
  ans = 1
else:
  ans += 1+math.ceil((len(a)-k)/(k-1))

print(ans)
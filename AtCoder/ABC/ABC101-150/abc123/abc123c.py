n = int(input())
a = []
for i in range(5):
  a.append(int(input()))

import math
ans = max(5, math.ceil(n/min(a))+4)
print(ans)
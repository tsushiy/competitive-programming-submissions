a, b, x = list(map(int, input().split()))
ma = a*a*b

import math

if (ma / 2 > x):
  y = a*b*b/(2*x)
  ans = math.degrees(math.atan(y))
  print(ans)
else:
  y = 2*(a*a*b-x)/(a*a*a)
  ans = math.degrees(math.atan(y))
  print(ans)
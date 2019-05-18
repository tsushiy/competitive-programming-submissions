n = int(input())
a = list(map(abs, map(int, input().split())))
a.sort()
from bisect import bisect_left
ans = 0
for i, e in enumerate(a):
  x = bisect_left(a, (e+1)//2)
  ans += i-x
print(ans)
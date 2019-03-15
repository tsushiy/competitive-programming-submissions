l, x, y, s, d = list(map(int, input().split()))
if s<=d:
  k = d-s
else:
  k = d+l-s
if x>=y:
  ans = k/(x+y)
else:
  ans = min(k/(x+y), (l-k)/(y-x))
print(ans)
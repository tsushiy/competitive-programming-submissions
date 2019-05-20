from bisect import bisect_left, bisect_right
a, b, q = list(map(int, input().split()))
s = [int(input()) for i in range(a)]
t = [int(input()) for i in range(b)]
for i in range(q):
  x = int(input())
  ss = bisect_left(s, x)
  tt = bisect_left(t, x)
  d1, d2, d3, d4 = 1e12, 1e12, 1e12, 1e12
  if ss-1>=0 and tt-1>=0:
    d1 = max((x-s[ss-1]), (x-t[tt-1]))
  if ss-1>=0 and tt<b:
    d2 = (x-s[ss-1])+(t[tt]-x)+min((x-s[ss-1]), (t[tt]-x))
  if ss<a and tt-1>=0:
    d3 = (s[ss]-x)+(x-t[tt-1])+min((s[ss]-x), (x-t[tt-1]))
  if ss<a and tt<b:
    d4 = max((s[ss]-x), (t[tt]-x))
  ans = min(d1, d2, d3, d4)
  print(ans)
n = int(input())
a = list(map(int, input().split()))
min_ = 1e9
flag = 0
ans = 0
for e in a:
  if e<0:
    flag = (flag+1) % 2
  if min_>abs(e):
    min_ = abs(e)
  ans += abs(e)
if flag:
  print(ans-min_*2)
else:
  print(ans)
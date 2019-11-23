x, y = list(map(int, input().split()))
ans = 0

if x==1 and y==1:
  ans += 400000

if x == 3:
  ans += 100000
elif x == 2:
  ans += 200000
elif x == 1:
  ans += 300000


if y == 3:
  ans += 100000
elif y == 2:
  ans += 200000
elif y == 1:
  ans += 300000

print(ans)
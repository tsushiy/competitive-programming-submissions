n, m = list(map(int, input().split()))
s = [list(map(int, input().split())) for i in range(m)]
p = list(map(int, input().split()))
ans = 0
for i in range(1<<n):
  good = True
  for j in range(m):
    cur = 0
    for e in s[j][1:]:
      if i&(1<<(e-1)):
        cur += 1
    if cur%2!=p[j]:
      good = False
      break
  if good:
    ans += 1
print(ans)
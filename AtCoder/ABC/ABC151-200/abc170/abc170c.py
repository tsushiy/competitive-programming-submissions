x, n = list(map(int, input().split()))
if n == 0:
  print(x)
  exit()
p = list(map(int, input().split()))
d = 1e9
ans = 0
for e in range(200, -1, -1):
  dd = abs(e - x)
  if e not in p and dd <= d:
    d = dd
    ans = e
print(ans)
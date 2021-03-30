a, b = list(map(int, input().split()))
c, d = list(map(int, input().split()))
ans = -1e9
for x in range(a, b + 1):
  for y in range(c, d + 1):
    ans = max(ans, x - y)
print(ans)

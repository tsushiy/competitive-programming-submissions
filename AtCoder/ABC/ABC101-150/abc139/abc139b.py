a, b = list(map(int, input().split()))
cur = 1
ans = 0
while cur < b:
  cur += (a-1)
  ans += 1
print(ans)
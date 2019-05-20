n, x = list(map(int, input().split()))
l = list(map(int, input().split()))
ans = 1
cur = 0
for e in l:
  cur += e
  if cur<=x:
    ans += 1
print(ans)
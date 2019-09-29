n, k = list(map(int, input().split()))
h = list(map(int, input().split()))
ans = 0
for e in h:
  if e >= k:
    ans += 1
print(ans)
n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = a[0]
for i in range(1, n):
  ans *= a[i]
  if ans > 1e18:
    ans = -1
    break
print(ans)
n, t = list(map(int, input().split()))
a = [int(input()) for i in range(n)]
ans = 0
for i in range(1, n):
  ans += min(t, a[i]-a[i-1])
ans += t
print(ans)
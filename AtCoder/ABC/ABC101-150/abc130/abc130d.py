from bisect import bisect_left
n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
ans = 0
s = [0 for i in range(n)]
s[0] = a[0]
for i in range(1, n):
  s[i] = s[i-1]+a[i]
for i in range(n):
  cur = k-a[i]
  j = bisect_left(s, s[i]+(k-a[i]))
  ans += n-j
print(ans)
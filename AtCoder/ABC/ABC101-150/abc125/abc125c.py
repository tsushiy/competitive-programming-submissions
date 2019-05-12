def gcd(a, b):
  return gcd(b, a%b) if b else a

n = int(input())
a = list(map(int, input().split()))
l = [0 for i in range(n+1)]
r = [0 for i in range(n+1)]
ans = 0

for i in range(n):
  l[i+1] = gcd(a[i], l[i])
  r[n-i-1] = gcd(a[n-i-1], r[n-i])
for i in range(n):
  ans = max(ans, gcd(l[i], r[i+1]))
print(ans)

n = int(input())
a = list(map(int, input().split()))

def gcd(a, b):
  return gcd(b, a%b) if b else a

ans = a[0]
for i in range(n):
  ans = gcd(ans, a[i])
print(ans)
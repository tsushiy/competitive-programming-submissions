n, X = list(map(int, input().split()))
x = list(map(int, input().split()))
x.append(X)
x.sort()
s = [0 for i in range(n)]
for i in range(n):
  s[i] = x[i+1]-x[i]

def gcd(a, b):
  return gcd(b, a%b) if b else a

ans = s[0]
for i in range(n):
  ans = gcd(ans, s[i])
print(ans)
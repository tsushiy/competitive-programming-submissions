n = int(input())
t = [int(input()) for i in range(n)]

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

def lcm(a, b):
  g = gcd(a, b)
  return a*b//g

ans = 1
for i in range(n):
  ans = lcm(ans, t[i])
print(ans)
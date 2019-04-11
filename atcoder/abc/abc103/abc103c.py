n = int(input())
a = list(map(int, input().split()))

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

def lcm(a, b):
  g = gcd(a, b)
  return a*b//g

l = 1
for ele in a:
  l = lcm(l, ele)

ans = 0
for ele in a:
  ans += (l-1)%ele
print(ans)
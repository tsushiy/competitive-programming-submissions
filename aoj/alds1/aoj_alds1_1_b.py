x, y = list(map(int, input().split()))

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

print(gcd(x, y))
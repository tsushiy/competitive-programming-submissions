n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

def gcd(a, b):
  if a<b:
    a, b = b, a
  if b==0:
    return a
  return gcd(b, a%b)

from functools import reduce
g = reduce(gcd, a)

if k%g==0 and k<=max(a):
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")
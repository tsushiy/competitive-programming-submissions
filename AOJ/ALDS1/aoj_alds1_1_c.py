n = int(input())

def isPrime(x):
  if x==2:
    return True
  elif x<2 or x%2==0:
    return False
  for i in range(3, int(x**0.5)+1, 2):
    if x%i==0:
      return False
  return True

ans = 0
for i in range(n):
  x = int(input())
  if isPrime(x):
    ans += 1
print(ans)
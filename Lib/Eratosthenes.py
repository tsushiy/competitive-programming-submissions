# エラトステネスの篩
MAX = 10*5+1
p = [1]*MAX
p[0], p[1] = 0, 0
for i in range(2, MAX, 2):
  p[i] = 0
for i in range(3, int(MAX**0.5)+1, 2):
  if p[i]:
    for j in range(i*2, MAX, i):
      p[j] = 0
for i, ele in enumerate(p):
  if ele>0:
    print(i)

# 単純な素数判定
def isPrime(x):
  if x==2:
    return True
  elif x<2 or x%2==0:
    return False
  for i in range(3, int(x**0.5)+1, 2):
    if x%i==0:
      return False
  return True
n = int(input())
def get_divisor(x):
  divisor = set()
  for i in range(1, int(x**(1/2))+1):
    if x%i==0:
      divisor.add(i)
      divisor.add(x//i)
  return divisor
ans = 0
for i in range(1, n+1, 2):
  if len(get_divisor(i))==8:
    ans += 1
print(ans)
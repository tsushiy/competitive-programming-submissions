n = int(input())
ans = 0
if n==1 or n==2:
  print(0)
  exit()
elif n<6:
  print(n-1)
  exit()
for i in range(1, int(n**(1/2))+2):
  k = (n-i)//i
  if n%k == n//k:
    ans += k
print(ans)
n = int(input())
ans = n
for i in range(n+1):
  cc=0
  t=i
  while t>0:
    cc=cc+t%6
    t=t//6
  t=n-i
  while t>0:
    cc=cc+t%9
    t=t//9
  ans=min(ans, cc)
print(ans)
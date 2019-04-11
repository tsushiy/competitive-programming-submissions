a = []
ans = 0
for i in range(5):
  e = int(input())
  if e%10==0:
    ans+=e
  else:
    ans+=e+10-(e%10)
    a.append(e)

a.sort(key=lambda x:x%10)
if len(a)>0:
  ans-=(10-a[0]%10)

print(ans)

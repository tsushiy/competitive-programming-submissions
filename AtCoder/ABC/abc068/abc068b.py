n = int(input())
a = []
for i in range(7):
  a.append(2**i)
for i in range(7):
  if n>=a[i]:
    ans=a[i]
print(ans)
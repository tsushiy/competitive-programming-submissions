n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
  while True:
    if a[i]%2!=0 and a[i]%3!=2:
      break
    else:
      a[i]-=1
      ans+=1
print(ans)
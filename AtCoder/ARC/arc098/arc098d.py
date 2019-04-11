n = int(input())
a = list(map(int, input().split()))

t = a[0]
ans = 0
r = 1

for l in range(n):
  while r<n and t^a[r] == t+a[r]:
    t+=a[r]
    r+=1
  if r==l:
    l=r+1
  ans += r-l
  t -= a[l]

print(ans)
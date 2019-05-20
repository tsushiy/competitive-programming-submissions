n, k = list(map(int, input().split()))
s = [int(input()) for i in range(n)]

if 0 in set(s):
  print(n)
  exit()
if k==0:
  print(0)
  exit()

l = 0
r = 0
ans = 0
cur = s[0]
while l<=r and r<=n-1:
  if r==n-1 and cur<=k:
    ans = max(ans, r-l+1)
    break
  if cur<=k:
    ans = max(ans, r-l+1)
    r += 1
    cur *= s[r]
  else:
    cur /= s[l]
    l += 1
print(ans)
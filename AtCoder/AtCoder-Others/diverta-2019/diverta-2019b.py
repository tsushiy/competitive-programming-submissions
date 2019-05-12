r, g, b, n = list(map(int, input().split()))
ans = 0
for i in range(n//r+1):
  for j in range(n//b+1):
    ij = i*r + j*b
    k = (n-ij)//g
    if not (i==k==j==0) and (k>=0 and (n-ij)%g==0):
      ans += 1
print(ans)
n, q = map(int, input().split())
x = list(map(int, input().split()))
cd = [list(map(int, input().split())) for _ in range(q)]

for i in range(q):
  ans=0
  for j in range(n):
    if abs(x[j]-cd[i][0])<=cd[i][1]:
      ans+=abs(x[j]-cd[i][0])
    else:
      ans+=cd[i][1]
  print(ans)
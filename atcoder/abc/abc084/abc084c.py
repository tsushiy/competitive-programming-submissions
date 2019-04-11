n = int(input())
csf = [list(map(int, input().split())) for _ in range(n-1)]

for i in range(n-1):
  t = 0
  for j in range(i, n-1):
    if csf[j][1]>t:
      t+=(csf[j][1]-t)
    if t%csf[j][2]!=0:
      t+=(csf[j][2]-t%csf[j][2])
    t+=csf[j][0]
  print(t)
print(0)
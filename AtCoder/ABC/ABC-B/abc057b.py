n, m = list(map(int, input().split()))
ab = []
cd = []
for i in range(n):
  ab.append(list(map(int, input().split())))
for i in range(m):
  cd.append(list(map(int, input().split())))

for i in range(n):
  t = float("INF")
  for j in range(m):
    if abs(ab[i][0]-cd[j][0])+abs(ab[i][1]-cd[j][1])<t:
      t = abs(ab[i][0]-cd[j][0])+abs(ab[i][1]-cd[j][1])
      ans = j+1
  print(ans)
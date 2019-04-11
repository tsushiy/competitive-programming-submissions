d, g = list(map(int, input().split()))
pc = []
for i in range(d):
  pt, ct = list(map(int, input().split()))
  pc.append((pt, ct, (i+1)*100*pt+ct))

ans = float("INF")
for i in range(d):
  t = 0
  for j in range(pc[i][0]):
    t += (i+1)*100
    if j==pc[i][0]-1:
      t += pc[i][1]
    if t>=g:
      ans = min(ans, j+1)
      break
if ans!=float("INF"):
  print(ans)
else:
  pass
print(pc)
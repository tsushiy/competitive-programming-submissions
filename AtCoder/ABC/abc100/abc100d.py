n, m = map(int, input().split())
xyz = []
t = [[0, 0, 0] for _ in range(8)]
tt = [0]*8
ans = 0

for i in range(n):
  x, y, z = map(int, input().split())
  xyz.append([x, y, z])
  xyz[i].append(x+y+z)
  xyz[i].append(x+y-z)
  xyz[i].append(x-y+z)
  xyz[i].append(-x+y+z)
  xyz[i].append(x-y-z)
  xyz[i].append(-x+y-z)
  xyz[i].append(-x-y+z)
  xyz[i].append(-x-y-z)

from operator import itemgetter

for i in range(8):
  xyz.sort(key=itemgetter(i+3))
  for j in range(m):
    t[i][0] += xyz[j][0]
    t[i][1] += xyz[j][1]
    t[i][2] += xyz[j][2]
  tt[i] = abs(t[i][0]) + abs(t[i][1]) + abs(t[i][2])
  if ans < tt[i]:
    ans = tt[i]

print(ans)

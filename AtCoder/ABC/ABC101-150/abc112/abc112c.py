n = int(input())
xyh = [list(map(int, input().split())) for i in range(n)]
xyh.sort(key=lambda x: -x[2])
for cx in range(101):
  for cy in range(101):
    good = True
    h = xyh[0][2]+abs(cx-xyh[0][0])+abs(cy-xyh[0][1])
    for i in range(n):
      if xyh[i][2] != max(h-abs(cx-xyh[i][0])-abs(cy-xyh[i][1]), 0):
        good = False
        break
    if good:
      print(cx, cy, h)
      exit()
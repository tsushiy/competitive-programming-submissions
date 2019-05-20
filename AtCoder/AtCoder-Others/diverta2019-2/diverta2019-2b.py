n = int(input())
xy = [tuple(map(int, input().split())) for i in range(n)]
ans = n

for i in range(n):
  for j in range(n):
    if i==j:
      continue
    xt = xy[i][0]-xy[j][0]
    yt = xy[i][1]-xy[j][1]
    tmp = n
    for k in range(n):
      if (xy[k][0]+xt, xy[k][1]+yt) in xy:
        tmp -= 1
    ans = min(ans, tmp)

print(ans)
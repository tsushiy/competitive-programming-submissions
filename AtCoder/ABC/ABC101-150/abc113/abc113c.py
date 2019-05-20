n, m = list(map(int, input().split()))
ipy = []
num = [1 for i in range(n+1)]
ans = ["" for i in range(m)]
for i in range(m):
  p, y = list(map(int, input().split()))
  ipy.append([i, p, y])
ipy.sort(key=lambda x: x[2])
for i in range(m):
  ans[ipy[i][0]] = str(ipy[i][1]).zfill(6)+str(num[ipy[i][1]]).zfill(6)
  num[ipy[i][1]] += 1
for e in ans:
  print(e)
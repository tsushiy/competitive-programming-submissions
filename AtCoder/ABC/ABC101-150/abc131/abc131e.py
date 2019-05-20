n, k = list(map(int, input().split()))
if k>(n-2)*(n-1)//2:
  print(-1)
  exit()
m = 0
edge = [[] for i in range(n)]
edge[0].append(1)
m += 1
for i in range(2, n):
  edge[1].append(i)
  m += 1
rem = (n-2)*(n-1)//2-k
for i in range(n):
  if rem==0:
    break
  if i==1:
    continue
  for j in range(i+1, n):
    if rem==0:
      break
    if j==1:
      continue
    edge[i].append(j)
    m += 1
    rem -= 1
print(m)
for i, row in enumerate(edge):
  for e in row:
    print(i+1, e+1)
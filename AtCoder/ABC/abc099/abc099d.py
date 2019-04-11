N, C = map(int, input().split())
d = []
c = []
t = [[0]*C, [0]*C, [0]*C]
for _ in range(C):
  d.append(list(map(int, input().split())))
for _ in range(N):
  c.append(list(map(int, input().split())))

for i in range(N):
  for j in range(N):
    t[(i+j)%3][c[i][j]-1] += 1

ans=1000*N*N

for i in range(C):
  for j in range(C):
    if i!=j:
      for k in range(C):
        if i!=k and j!=k:
          tt=0
          for l in range(C):
            tt += d[l][i]*t[0][l] + d[l][j]*t[1][l]+d[l][k]*t[2][l]
          ans = min(ans, tt)
print(ans)
n, m, q = list(map(int, input().split()))
lr = [[0 for i in range(501)] for i in range(501)]
for i in range(m):
  lt, rt = list(map(int, input().split()))
  lr[lt][rt] += 1
for i in range(1, 501):
  for j in range(1, 501):
    lr[i][j] += lr[i][j-1]
for i in range(q):
  lt, rt = list(map(int, input().split()))
  ans = 0
  for j in range(lt, rt+1):
    ans += lr[j][rt]-lr[j][j-1]
  print(ans)
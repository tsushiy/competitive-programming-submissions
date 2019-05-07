n, m = list(map(int, input().split()))
A = [[0]*m for _ in range(n)]
B = [0]*m
for i in range(n):
  a = list(map(int, input().split()))
  for j in range(m):
    A[i][j] = a[j]
for i in range(m):
  B[i] = int(input())
for i in range(n):
  ans = 0
  for j in range(m):
    ans += A[i][j]*B[j]
  print(ans)
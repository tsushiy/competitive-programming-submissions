n = int(input())
a = [list(map(int, input().split())) for _ in range(2)]
b = [[0]*n for _ in range(2)]
b[0][0], b[1][0] = a[0][0], a[0][0]+a[1][0]
for i in range(1, n):
  b[0][i] = b[0][i-1]+a[0][i]
for i in range(1, n):
  b[1][i] = max(b[0][i], b[1][i-1])+a[1][i]
print(b[1][n-1])
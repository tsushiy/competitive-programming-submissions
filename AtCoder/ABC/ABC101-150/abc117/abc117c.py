n, m = list(map(int, input().split()))
if n>=m:
  print(0)
  exit()
x = list(map(int, input().split()))
x.sort()
start = [0 for i in range(n)]
s = [[0, i] for i in range(m)]
for i in range(1, m):
  s[i][0] = x[i]-x[i-1]
s.sort(reverse=True)
for i in range(1, n):
  start[i] = s[i-1][1]
ans = 0
for i in range(n):
  ans += x[start[i]-1]-x[start[i]]
print(ans)
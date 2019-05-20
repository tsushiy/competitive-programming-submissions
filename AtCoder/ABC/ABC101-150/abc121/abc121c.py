n, m = list(map(int, input().split()))
ab = [list(map(int, input().split())) for i in range(n)]
ab.sort(key=lambda x: x[0])
ans = 0
cur = 0
for i in range(n):
  if cur+ab[i][1]<m:
    ans += ab[i][0]*ab[i][1]
    cur += ab[i][1]
  else:
    ans += (m-cur)*ab[i][0]
    break
print(ans)
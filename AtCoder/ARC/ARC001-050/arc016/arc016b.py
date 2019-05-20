n = int(input())
ans = 0
g = [list(input()) for i in range(n)]
for i in range(9):
  flag = False
  for j in range(n):
    if g[j][i]=='x':
      ans += 1
      if flag:
        ans += 1
        flag = False
    elif g[j][i]=='o':
      flag = True
      if j==n-1:
        ans += 1
    else:
      if flag:
        ans += 1
        flag = False
print(ans)
h, w = list(map(int, input().split()))
s = [input() for i in range(h)]
yoko = [[0 for i in range(w)] for i in range(h)]
tate = [[0 for i in range(w)] for i in range(h)]

ans = 0
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


for i in range(h):
  cur = 0
  b = 0
  e = 0
  flag = 0
  for j in range(w):
    if s[i][j]=="." and j==w-1:
      cur += 1
      e = j
      for k in range(b, e+1):
        yoko[i][k] = cur
      cur = 0
    elif flag and s[i][j]==".":
      cur += 1
    elif not flag and s[i][j]==".":
      cur = 1
      flag = 1
      b = j
    elif flag and s[i][j]=="#":
      flag = 0
      e = j-1
      for k in range(b, e+1):
        yoko[i][k] = cur
      cur = 0
      b = j+1
    elif s[i][j]=="." and j==w-1:
      cur += 1
      e = j-1
      for k in range(b, e+1):
        yoko[i][k] = cur
      cur = 0
    else:
      b = j+1


for j in range(w):
  cur = 0
  b = 0
  e = 0
  flag = 0
  for i in range(h):
    if s[i][j]=="." and i==h-1:
      cur += 1
      e = i
      for k in range(b, e+1):
        tate[k][j] = cur
      cur = 0
    if flag and s[i][j]==".":
      cur += 1
    elif not flag and s[i][j]==".":
      cur = 1
      flag = 1
      b = i
    elif flag and s[i][j]=="#":
      flag = 0
      e = i-1
      for k in range(b, e+1):
        tate[k][j] = cur
      cur = 0
      b = i+1
    elif s[i][j]=="." and i==h-1:
      cur += 1
      e = i-1
      for k in range(b, e+1):
        tate[k][j] = cur
      cur = 0
    else:
      b = i+1

ans = 0
for i in range(h):
  for j in range(w):
    if yoko[i][j]>0 and tate[i][j]>0:
      ans = max(ans, yoko[i][j]+tate[i][j]-1)
    else:
      ans = max(ans, yoko[i][j]+tate[i][j])
print(ans)
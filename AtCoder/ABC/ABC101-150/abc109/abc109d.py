h, w = list(map(int, input().split()))
a = [list(map(int, input().split())) for i in range(h)]
ans = []
for i in range(h):
  for j in range(w):
    if i==h-1 and j==w-1:
      pass
    elif j==w-1 and a[i][j]%2==1:
      a[i+1][j] += 1
      ans.append((i+1, j+1, i+2, j+1))
    elif a[i][j]%2==1:
      a[i][j+1] += 1
      ans.append((i+1, j+1, i+1, j+2))
print(len(ans))
for e in ans:
  print(*e)
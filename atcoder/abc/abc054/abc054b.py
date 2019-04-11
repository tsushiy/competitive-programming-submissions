n, m = list(map(int, input().split()))
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]
for i in range(n-m+1):
  for j in range(n-m+1):
    flag = False
    for k in range(m):
      for l in range(m):
        if a[i+k][j+l]==b[k][l]:
          pass
        else:
          flag = True
          break
      if flag:
        break
    if flag==False:
      print("Yes")
      exit()
print("No")
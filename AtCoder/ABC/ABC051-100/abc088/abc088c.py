c = [list(map(int, input().split())) for _ in range(3)]
for i in range(3):
  for j in range(i+1, 3):
    if (c[i][0]-c[j][0])==(c[i][1]-c[j][1])==(c[i][2]-c[j][2]):
      pass
    else:
      print("No")
      exit()
print("Yes")
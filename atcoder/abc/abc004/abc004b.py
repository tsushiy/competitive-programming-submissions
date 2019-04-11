s = [[0]*4 for i in range(4)]
for i in range(4):
  c = input().split()
  for j in range(4):
    s[3-i][3-j] = c[j]
for ele in s:
  print(" ".join(ele))
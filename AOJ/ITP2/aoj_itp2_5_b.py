n = int(input())
a = [input().split() for i in range(n)]

for i in range(4, -1, -1):
  if i==4 or i==2:
    a.sort(key=lambda x:x[i])
  else:
    a.sort(key=lambda x:int(x[i]))
for ele in a:
  print(" ".join(map(str, ele)))
n = int(input())
xy = [list(map(int, input().split())) for i in range(n)]
xy.sort(key=lambda x:x[1])
xy.sort(key=lambda x:x[0])
for ele in xy:
  print(ele[0], ele[1])
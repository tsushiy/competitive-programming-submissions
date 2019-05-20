n, k = list(map(int, input().split()))
t = [list(map(int, input().split())) for i in range(n)]
flag = False
from itertools import product
p = [[i for i in range(k)] for j in range(n)]
for pt in product(*p):
  cur = 0
  for i in range(n):
    cur ^= t[i][pt[i]]
  if cur==0:
    flag = True
if flag:
  print("Found")
else:
  print("Nothing")
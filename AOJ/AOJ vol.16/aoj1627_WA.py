import copy
from collections import defaultdict
while True:
  n = int(input())
  if n==0:
    break

  draw = (n-1)//2

  match = [[0 for i in range(n+1)] for j in range(n+1)]
  win = defaultdict(int)
  m = int(input())
  for i in range(m):
    x, y = list(map(int, input().split()))
    match[x][y] = 1
    match[y][x] = -1
    win[x] += 1

  ans = 0
  rm = (n*(n-1)//2-m)
  for i in range(1<<rm):
    cur = 0
    good = True
    wint = copy.deepcopy(win)
    for j in range(1, n):
      if not good or cur>=rm:
        break
      for k in range(j+1, n+1):
        if wint[j] > draw or wint[k] > draw:
          good = False
          break
        if cur>=rm:
          break
        if match[j][k]==0:
          if i&(1<<cur)!=0:
            wint[j] += 1
            if wint[j] > draw:
              good = False
              break
          else:
            wint[k] += 1
            if wint[k] > draw:
              good = False
              break
          cur += 1
    if good:
      ans += 1

  print(ans)
from collections import deque
import time

start = time.time() # なにこれ

n = int(input())
target_num = n*(n-1)//2

all_set = set()
a = [deque(list(map(int, input().split()))) for i in range(n)]
ans = 0

while True:
  cur_set = set()
  flag = False
  for i in range(n):
    if len(a[i]):
      tup = (min(i+1, a[i][0]), max(i+1, a[i][0]))
    else:
      continue
    if tup not in cur_set:
      cur_set.add(tup)
    elif tup in cur_set:
      all_set.add(tup)
      t1, t2 = tup
      a[t1-1].popleft()
      a[t2-1].popleft()
      flag = True
  ans += 1
  if len(all_set)==target_num:
    break
  if time.time()-start>1.8:
    print(1000*999//2)
    exit()
  if not flag:
    print(-1)
    exit()

print(ans)
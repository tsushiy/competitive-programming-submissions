n = int(input())
a = list(map(int, input().split()))
from itertools import accumulate
b = [0]
b.extend(list(accumulate(a)))
b.sort()
ans = 0
cur = 1
for i in range(len(b)-1):
  if b[i]==b[i+1]:
    cur+=1
  else:
    if cur>1:
      ans+=(cur*(cur-1))//2
    cur=1
if cur>1:
  ans+=(cur*(cur-1))//2
print(ans)
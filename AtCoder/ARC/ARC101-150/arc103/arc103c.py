from collections import defaultdict
n = int(input())
v = list(map(int, input().split()))
d1 = defaultdict(int)
d2 = defaultdict(int)
for i in range(0, n, 2):
  d1[v[i]]+=1
  d2[v[i+1]]+=1
l1 = list(d1.items())
l2 = list(d2.items())
l1.sort(key=lambda x: -x[1])
l2.sort(key=lambda x: -x[1])
t1 = l1[0][1]
t2 = l2[0][1]
t3 = l1[1][1] if len(l1)>1 else 0
t4 = l2[1][1] if len(l2)>1 else 0
if l1[0][0]==l2[0][0]:
  ans = min(n-t1-t4, n-t2-t3)
else:
  ans = n-t1-t2
print(ans)
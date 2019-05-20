from collections import defaultdict
while True:
  n, q = list(map(int, input().split()))
  if n==0:
    break

  t = defaultdict(int)
  for i in range(n):
    d = list(map(int, input().split()))
    for j in range(1, len(d)):
      t[d[j]]+=1
  tt = sorted(t.items())
  tt.sort(key=lambda x: -x[1])
  if len(tt)==0 or tt[0][1]<q:
    print(0)
  else:
    print(tt[0][0])
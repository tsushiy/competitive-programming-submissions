from bisect import bisect_left
n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  k = int(input())
  t = bisect_left(a, k)
  if t>=n or a[t]!=k:
    print(0)
  else:
    print(1)
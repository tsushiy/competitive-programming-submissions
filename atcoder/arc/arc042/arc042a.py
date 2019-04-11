n, m = list(map(int, input().split()))
a = [int(input()) for i in range(m)]
from collections import defaultdict
d = defaultdict(bool)
for ele in a[::-1]:
  if not d[ele]:
    print(ele)
    d[ele] = True
for i in range(1, n+1):
  if not d[i]:
    print(i)
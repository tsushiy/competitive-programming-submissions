from collections import defaultdict
n = int(input())
a, b = list(map(int, input().split()))
k = int(input())
p = list(map(int, input().split()))
d = defaultdict(bool)
d[a], d[b] = True, True
for ele in p:
  if d[ele]:
    print("NO")
    exit()
  d[ele] = True
print("YES")
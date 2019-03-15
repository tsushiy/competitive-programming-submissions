n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  b, e, k = list(map(int, input().split()))
  print(a[b:e].count(k))
n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  c, b, e = list(map(int, input().split()))
  if c==0:
    print(min(a[b:e]))
  else:
    print(max(a[b:e]))
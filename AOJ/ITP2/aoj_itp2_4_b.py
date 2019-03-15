n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  b, m, e = list(map(int, input().split()))
  a = a[:b]+a[m:e]+a[b:m]+a[e:]
print(" ".join(map(str, a)))
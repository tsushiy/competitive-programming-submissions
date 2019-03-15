n = int(input())
a = list(map(int, input().split()))
q = int(input())
for i in range(q):
  b, e = list(map(int, input().split()))
  if b==0:
    a = a[e-1::-1]+a[e:]
  else:
    a = a[:b]+a[e-1:b-1:-1]+a[e:]
print(" ".join(map(str, a)))
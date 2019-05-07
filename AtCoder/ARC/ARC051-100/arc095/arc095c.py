n = int(input())
x = list(map(int, input().split()))
b = sorted(x)
m1 = b[n//2-1]
m2 = b[n//2]
for i in range(n):
  if x[i]<=m1:
    print(m2)
  else:
    print(m1)
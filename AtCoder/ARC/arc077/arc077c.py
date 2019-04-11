n = int(input())
a = list(map(int, input().split()))
b = []
if len(a)%2==0:
  for i in range(len(a)-1, 0, -2):
    b.append(a[i])
  for i in range(0, len(a), 2):
    b.append(a[i])
else:
  for i in range(len(a)-1, -1, -2):
    b.append(a[i])
  for i in range(1, len(a), 2):
    b.append(a[i])
print(" ".join(map(str, b)))
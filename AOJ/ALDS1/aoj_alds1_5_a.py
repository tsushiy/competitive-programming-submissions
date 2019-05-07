n = int(input())
a = list(map(int, input().split()))
q = int(input())
m = list(map(int, input().split()))
b = set()
for i in range(2**n):
  t = 0
  for j in range(n):
    if i>>j&1:
      t += a[j]
  b.add(t)
for ele in m:
  if ele in b:
    print("yes")
  else:
    print("no")
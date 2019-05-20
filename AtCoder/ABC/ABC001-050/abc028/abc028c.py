a = list(map(int, input().split()))
l = set()
for i in range(5):
  for j in range(5):
    for k in range(5):
      if i==j or j==k or k==i:
        continue
      s = a[i]+a[j]+a[k]
      l.add(s)
print(sorted(l)[-3])
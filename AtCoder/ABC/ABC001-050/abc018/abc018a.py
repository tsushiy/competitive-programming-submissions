a = [int(input()) for _ in range(3)]
for i in range(3):
  t = 1
  for j in range(3):
    if i==j:
      continue
    if a[i]<a[j]:
      t+=1
  print(t)
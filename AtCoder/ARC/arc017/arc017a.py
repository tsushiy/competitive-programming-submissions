n = int(input())
p = [1]*(n+1)
p[0] = 0
p[1] = 0
for i in range(2, n+1, 2):
  p[i] = 0
for i in range(3, int((n+1)**0.5)+1, 2):
  if p[i]:
    for j in range(i*2, n+1, i):
      p[j] = 0
if p[n]:
  print("YES")
else:
  print("NO")
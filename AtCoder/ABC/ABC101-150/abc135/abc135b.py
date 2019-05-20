n = int(input())
p = list(map(int, input().split()))
t = 0
for i in range(n):
  if i+1!=p[i]:
    t += 1
if t==0 or t==2:
  print("YES")
else:
  print("NO")
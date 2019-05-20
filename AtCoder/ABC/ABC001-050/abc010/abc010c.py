txa, tya, txb, tyb, t, v = list(map(int, input().split()))
n = int(input())
dist = t*v
ans = False
for i in range(n):
  x, y = list(map(int, input().split()))
  dista = ((x-txa)**2+(y-tya)**2)**(1/2)
  distb = ((x-txb)**2+(y-tyb)**2)**(1/2)
  if dista+distb<=dist:
    ans = True
if ans:
  print("YES")
else:
  print("NO")
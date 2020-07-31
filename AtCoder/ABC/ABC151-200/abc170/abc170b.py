x, y = list(map(int, input().split()))
ok = False
for i in range(x+1):
  if i * 2 + (x-i) * 4 == y:
    ok = True
if ok:
  print("Yes")
else:
  print("No")
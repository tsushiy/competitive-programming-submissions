n = int(input())
a = 0
for i in range(n):
  s = input()
  if s == "A":
    a+=1
  else:
    a-=1

  if a<0:
    print("NO")
    exit()

if a==0:
  print("YES")
else:
  print("NO")

n = int(input())
s = input()
t = "b"
if s==t:
  print(0)
  exit()
for i in range(1, n+1):
  if i%3==1:
    t = "a"+t+"c"
  elif i%3==2:
    t = "c"+t+"a"
  else:
    t = "b"+t+"b"
  if s==t:
    print(i)
    exit()
print(-1)
e = list(map(int, input().split()))
b = int(input())
l = list(map(int, input().split()))
u = len(set(e)&set(l))
if u==6:
  print(1)
elif u==5 and b in l:
  print(2)
elif u==5:
  print(3)
elif u==4:
  print(4)
elif u==3:
  print(5)
else:
  print(0)
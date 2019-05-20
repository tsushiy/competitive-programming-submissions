n = int(input())
keta = len(str(n))
if keta==1 or keta==2:
  print(min(n, 9))
elif keta==3 or keta==4:
  print(min(n-90, 909))
elif keta==5 or keta==6:
  print(min(n-9090, 90909))
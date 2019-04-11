n=input()
sn=0
for ele in n:
  sn+=int(ele)
if int(n)%sn==0:
  print("Yes")
else:
  print("No")
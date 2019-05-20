s = input()
flag = True
for i, e in enumerate(s):
  if i%2==0 and e not in "RUD":
    flag = False
  elif i%2==1 and e not in "LUD":
    flag = False
if flag:
  print("Yes")
else:
  print("No")
x = input()
while True:
  if len(x)==0:
    print("YES")
    exit()
  elif x[-1]=="o" or x[-1]=="k" or x[-1]=="u":
    x = x[:-1]
  elif len(x)>=2 and x[-1]=="h" and x[-2]=="c":
    x = x[:-2]
  else:
    print("NO")
    exit()
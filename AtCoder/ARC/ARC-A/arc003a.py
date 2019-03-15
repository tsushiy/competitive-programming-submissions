n = int(input())
r = input()
s = 0
for ele in r:
  if ele=="A":
    s+=4
  elif ele=="B":
    s+=3
  elif ele=="C":
    s+=2
  elif ele=="D":
    s+=1
  else:
    pass
print(s/n)
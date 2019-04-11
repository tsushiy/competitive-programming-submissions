s = input()
cnt = 0
for ele in s:
  if cnt==0 and ele.lower()=="i":
    cnt+=1
  elif cnt==1 and ele.lower()=="c":
    cnt+=1
  elif cnt==2 and ele.lower()=="t":
    print("YES")
    exit()
print("NO")
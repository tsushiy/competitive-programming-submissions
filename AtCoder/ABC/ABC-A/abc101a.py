s=input()
ans=0
for ele in s:
  if ele=="+":
    ans+=1
  else:
    ans-=1
print(ans)
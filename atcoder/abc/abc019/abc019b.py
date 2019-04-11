s = input()
ans = ""
t = ""
cnt = 0
for ele in s:
  if t==ele:
    cnt+=1
  else:
    if cnt!=0:
      ans += t+str(cnt)
    t = ele
    cnt = 1
ans += t+str(cnt)
print(ans)
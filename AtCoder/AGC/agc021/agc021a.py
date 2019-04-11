n = input()
flag = False
ans = 0
for ele in n[-1:0:-1]:
  if ele!="9":
    flag = True
  ans+=9
if flag:
  ans += int(n[0])-1
else:
  ans += int(n[0])
print(ans)
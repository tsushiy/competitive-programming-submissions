n = int(input())
s = input()
cntW = 0
cntE = s[1:].count("E")
ans = cntE
for i in range(1, n):
  if s[i-1] == "W":
    cntW+=1
  if s[i]=="E":
    cntE-=1
  ans=min(ans, cntE+cntW)
print(ans)
s = input()
ans = len(s)
f = 0
if len(s)==2 and len(set(s))==1:
  print(1)
  exit()

for i in range(len(s)-1):
  if f==1:
    f = 2
    continue
  if f==2:
    f = 0
    continue
  if s[i]==s[i+1]:
    ans -= 1
    f = 1
print(ans)
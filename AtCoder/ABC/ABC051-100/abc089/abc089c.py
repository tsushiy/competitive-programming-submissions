n = int(input())
c = [0]*5
for _ in range(n):
  s = input()
  if s[0]=="M":
    c[0]+=1
  elif s[0]=="A":
    c[1]+=1
  elif s[0]=="R":
    c[2]+=1
  elif s[0]=="C":
    c[3]+=1
  elif s[0]=="H":
    c[4]+=1

ans = 0
for i in range(5):
  for j in range(i+1, 5):
    for k in range(j+1, 5):
      ans+=c[i]*c[j]*c[k]
print(ans)
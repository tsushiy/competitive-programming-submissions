s = input()
ans = 0
for i in range(2**(len(s)-1)):
  t=""
  for j in range(len(s)-1):
    if format(i,"0"+str(len(s)-1)+"b")[j] == '1':
      t+=s[j]+"+"
    else:
      t+=s[j]
  t+=s[-1]
  ans+=eval(t)
print(ans)
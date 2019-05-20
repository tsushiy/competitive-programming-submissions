s = input()
t = input()
ans = set()
for i in range(len(s)-len(t)+1):
  cur = s[:i].replace("?", "a")
  for j in range(len(t)):
    if s[i+j]=="?" or s[i+j]==t[j]:
      cur += t[j]
    else:
      break
  cur += s[i+j+1:].replace("?", "a")
  if len(cur)==len(s):
    ans.add(cur)

if len(ans):
  print(sorted(ans)[0])
else:
  print("UNRESTORABLE")
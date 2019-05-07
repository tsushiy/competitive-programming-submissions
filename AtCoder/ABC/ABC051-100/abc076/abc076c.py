s = input()
t = input()
ans = []
if len(t)>len(s):
  print("UNRESTORABLE")
else:
  for i in range(len(s)-len(t)+1):
    st = ""
    for j in range(len(t)):
      if s[j+i]=="?" or s[j+i]==t[j]:
        st+=t[j]
      else:
        break
    if len(st)==len(t):
      st = s[:i]+st+s[i+len(t):]
      ans.append(st.replace("?", "a"))
  if len(ans):
    print(sorted(ans)[0])
  else:
    print("UNRESTORABLE")
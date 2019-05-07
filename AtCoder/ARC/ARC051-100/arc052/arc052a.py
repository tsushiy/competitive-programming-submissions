s = input()
for i in range(len(s)):
  if s[i] in "123456789":
    if i!=len(s)-1 and s[i+1] in "0123456789":
      print(s[i]+s[i+1])
    else:
      print(s[i])
    break
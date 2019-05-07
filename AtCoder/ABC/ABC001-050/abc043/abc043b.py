s = input()
t = ""
for i in range(len(s)):
  if s[i] == "0":
    t+="0"
  elif s[i] == "1":
    t+="1"
  else:
    t=t[:-1]
print(t)
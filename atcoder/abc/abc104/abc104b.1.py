s = list(input())
if s[0]=="A":
  s[0] = "a"
  flag = False
  for i, ele in enumerate(s[2:-1], 2):
    if ele == "C":
      s[i] = "c"
      flag = True
      break
  if flag and str(s).islower():
    print("AC")
  else:
    print("WA")
else:
  print("WA")
s = input()
num = set("1234567890")
ans = False
for e in s:
  if e in num:
    ans = True
if ans:
  print("leet")
else:
  print("Noleet")
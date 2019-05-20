s = input()
m = [i for i in range(1, 13)]
if int(s[2:]) in m and int(s[0:2]) in m:
  print("AMBIGUOUS")
elif int(s[2:]) in m:
  print("YYMM")
elif int(s[0:2]) in m:
  print("MMYY")
else:
  print("NA")
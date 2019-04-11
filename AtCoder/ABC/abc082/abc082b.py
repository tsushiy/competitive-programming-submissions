s = input()
t = input()
st = sorted(s)
tt = sorted(t)
tt.reverse()
if st<tt:
  print("Yes")
else:
  print("No")
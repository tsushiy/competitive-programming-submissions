n = input()
n = n.strip('0')
if n == n[::-1]:
  print("Yes")
else:
  print("No")

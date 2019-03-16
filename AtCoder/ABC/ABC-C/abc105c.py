n = int(input())
if n == 0:
  print(0)
  exit()
ans = ""
while n != 0:
  if n%-2 < 0:
    r = n%-2+2
    n = n//-2+1
  else:
    r = n%-2
    n = n//-2
  ans += str(r)
print(int(ans[::-1]))
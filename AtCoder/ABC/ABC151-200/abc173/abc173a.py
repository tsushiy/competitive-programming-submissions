n = int(input())
rem = n % 1000
if rem == 0:
  print(0)
else:
  print(1000 - rem)
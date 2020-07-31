n = int(input())
s = ""
while n > 0:
  rem = n % 26
  if rem == 0:
    rem = 26
  s += chr(96+rem)
  n //= 26
  if rem == 26:
    n -= 1
s = s[::-1]
print(s)
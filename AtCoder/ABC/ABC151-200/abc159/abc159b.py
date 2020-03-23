s = list(input())
n = len(s)
srev = list(reversed(s))
a = s[:(n-1)//2]
arev = list(reversed(a))
b = s[(n+3)//2-1:]
brev = list(reversed(b))
if s == srev and a == arev and b == brev:
  print("Yes")
else:
  print("No")

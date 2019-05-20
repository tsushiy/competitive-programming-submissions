n = int(input())
s = [1, 2, 3, 4, 5, 6]
loop = n//5
rem = n%5
t = s[loop%6:]+s[:loop%6]
for i in range(rem):
  t[i], t[i+1] = t[i+1], t[i]
for e in t:
  print(e, end='')
print()
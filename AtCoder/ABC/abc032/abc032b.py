s = input()
k = int(input())
sub = set()
for i in range(len(s)-k+1):
  t = ""
  for j in range(k):
    t += s[i+j]
  sub.add(t)
print(len(sub))
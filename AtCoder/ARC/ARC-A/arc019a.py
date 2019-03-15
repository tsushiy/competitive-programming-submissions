s = input()
c = "ODIZSB"
n = "001258"
for i in range(6):
  s = s.replace(c[i], n[i])
print(s)
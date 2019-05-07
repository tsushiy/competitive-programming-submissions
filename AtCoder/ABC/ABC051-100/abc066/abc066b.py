s = input()
for i in range(1, len(s)):
  t = s[:len(s)-i]
  if len(t)%2==1:
    continue
  if t[:len(t)//2]==t[len(t)//2:]:
    print(len(t))
    exit()
print(1)
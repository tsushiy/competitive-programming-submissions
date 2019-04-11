s = input()
for e1, e2 in zip(s, s[::-1]):
  if e1==e2 or e1=="*" or e2=="*":
    continue
  else:
    print("NO")
    exit()
print("YES")
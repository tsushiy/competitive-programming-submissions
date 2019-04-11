s = input()
anslist = [0]
ans = 0
acgt = ["A", "C", "G", "T"]
for e in s:
  if e in acgt:
    ans += 1
  else:
    anslist.append(ans)
    ans = 0
anslist.append(ans)
print(max(anslist))
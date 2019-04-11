w = input()
ans = 0
while True:
  s = input().split()
  if s==["END_OF_TEXT"]:
    break
  for i in range(len(s)):
    s[i] = s[i].lower()
  ans += s.count(w)
print(ans)
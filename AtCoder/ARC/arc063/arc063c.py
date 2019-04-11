s = input()
c1, c2 = s[0], s[-1]
cnt1, cnt2 = 0, 0
for i in range(1, len(s)):
  if c1!=s[i]:
    cnt1 += 1
    c1 = s[i]
for i in range(len(s)-2, -1, -1):
  if c2!=s[i]:
    cnt2 += 1
    c2 = s[i]
print(min(cnt1, cnt2))
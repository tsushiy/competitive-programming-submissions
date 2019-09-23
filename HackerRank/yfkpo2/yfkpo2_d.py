s = input()
ans = []
cnt = 1
for i in range(1, len(s)):
  if s[i]==s[i-1]=='|':
    ans.append(cnt)
    cnt = 1
  elif s[i]=='|':
    cnt += 1
ans.append(cnt)
print(*ans)
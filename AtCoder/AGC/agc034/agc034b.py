s = input()
s = s[::-1]
ans = 0
cnt = 0
pos = 0
flag = 0
while pos<len(s):
  if s[pos] == "A":
    ans += cnt
  elif flag and s[pos] == "B":
    flag = 0
    cnt += 1
  elif s[pos] == "B":
    cnt = 0
  elif not flag and s[pos] == "C":
    cnt = 0
  elif s[pos] == "C":
    flag = 1
  pos += 1
print(ans)
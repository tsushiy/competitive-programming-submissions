s = input()
ans = 1e9
for i in range(len(s)-2):
  ans = min(ans, abs(753-int(s[i:i+3])))
print(ans)
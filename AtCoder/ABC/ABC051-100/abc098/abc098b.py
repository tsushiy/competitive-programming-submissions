n = int(input())
s = input()
ans = 0
for i in range(n-1):
  ans = max(ans, len(set(s[:i+1])&set(s[i+1:])))
print(ans)
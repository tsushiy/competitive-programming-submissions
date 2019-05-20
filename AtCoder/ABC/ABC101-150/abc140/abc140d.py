n, k = list(map(int, input().split()))
s = input()

ans = 0
rev = 0
for i in range(1, n):
  if s[i-1]==s[i]:
    ans += 1
  else:
    rev += 1
ans += min(k*2, rev)
print(ans)
s = input()
l = len(s)
a = [0 for i in range(l)]
cur = 0
for i, ele in enumerate(s[::-1]):
  a[i] = cur
  if ele =="W":
    cur += 1

ans = 0
for i in range(l):
  if s[i]=="B":
    ans += a[l-i-1]
print(ans)
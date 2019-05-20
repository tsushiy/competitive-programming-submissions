s = input()
k = int(input())
cur = 0
for i in range(len(s)):
  if s[i]!="1":
    print(s[i])
    break
  cur += 1
  if cur==k:
    print(1)
    break
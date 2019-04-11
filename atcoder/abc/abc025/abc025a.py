s = input()
n = int(input())
t = set()
for i in range(len(s)):
  for j in range(i, len(s)):
    t.add(s[i]+s[j])
    t.add(s[j]+s[i])
print(sorted(t)[n-1])
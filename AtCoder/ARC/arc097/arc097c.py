s = input()
k = int(input())

t = set()

for i in range(len(s)):
  tt = ""
  for j in range(i, min(i+5, len(s))):
    tt+=s[j]
    t.add(tt)

print(sorted(t)[k-1])
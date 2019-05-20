s = input()
k = int(input())
d = set()
for i in range(1, 6):
  for j in range(len(s)):
    d.add(s[j:j+i])
print(sorted(d)[k-1])
n = int(input())
a = list(map(int, input().split()))
a.sort()
s = set(a)
ans = 0
found = set()
for e in a:
  if e not in found:
    ans += 1
  while e<=10**9:
    if e in s:
      found.add(e)
    e *= 2
print(ans)
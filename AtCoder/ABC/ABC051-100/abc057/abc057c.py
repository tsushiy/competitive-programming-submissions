n = int(input())
ans = 1e9
for i in range(1, int(n**(1/2))+1):
  j = n/i
  if j.is_integer():
    j = int(j)
    ans = min(ans, max(len(str(i)), len(str(j))))
print(ans)
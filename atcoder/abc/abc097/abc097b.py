x = int(input())
ans = 1
for i in range(1, 32):
  for j in range(2, 11):
    if i**j<=x:
      ans=max(ans, i**j)
print(ans)
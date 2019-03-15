a, b, c = list(map(int, input().split()))
ans = 0
if a%2==b%2==c%2:
  pass
elif a%2==b%2:
  a, b = a+1, b+1
  ans += 1
elif a%2==c%2:
  a, c = a+1, c+1
  ans += 1
else:
  b, c = b+1, c+1
  ans += 1

t = max(a, b, c)
ans += abs(t-a)//2+abs(t-b)//2+abs(t-c)//2
print(ans)
n = int(input())
ans = ""
if n==0:
  print(0)
  exit()
while n!=0:
  n, r = n//(-2), n%(-2)
  if r<0:
    r += 2
    n += 1
  ans += str(r)
print(ans[::-1])
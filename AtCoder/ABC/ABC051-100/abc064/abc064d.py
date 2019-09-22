n = int(input())
s = input()
l = 0
ans = ""
for e in s:
  if e==')':
    if l<=0:
      ans += '('
    else:
      l -= 1
  else:
    l += 1
print(ans + s + ')'*l)
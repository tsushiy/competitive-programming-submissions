s = input()
ans = 0
p = 0
g = 0
for e in s:
  if e=='g':
    if p==g:
      g += 1
    else:
      p += 1
      ans += 1
  else:
    if p==g:
      g += 1
      ans -= 1
    else:
      p += 1
print(ans)
n, a, b, c, d = list(map(int, input().split()))
s = list(input())
a = a-1
b = b-1
c = c-1
d = d-1
s[a] = "A"
s[b] = "B"
ans = True
flag = 0

while a<n and b<n:
  while a<b:
    if a==c:
      break
    elif a+1<n and a+1<b and s[a+1]==".":
      s[a] = "."
      s[a+1] = "A"
      a += 1
    elif a+2<n and a+2<b and s[a+2]==".":
      s[a] = "."
      s[a+2] = "A"
      a += 2
    else:
      break

  if a+2<n and d<c and s[a+1]=="B" and s[a+2]==".":
    s[a] = "."
    s[a+2] = "A"
    a += 2

  if b<a:
    while a<n:
      if a==c:
        break
      elif a+1<n and s[a+1]==".":
        s[a] = "."
        s[a+1] = "A"
        a += 1
      elif a+2<n and s[a+2]==".":
        s[a] = "."
        s[a+2] = "A"
        a += 2
      else:
        ans = False
        break

  if a==c and b==d:
    break
  elif b+1<n and s[b+1]==".":
    s[b] = "."
    s[b+1] = "B"
    b += 1
  elif b+2<n and s[b+2]==".":
    s[b] = "."
    s[b+2] = "B"
    b += 2
  else:
    ans = False
    break

if ans:
  print("Yes")
else:
  print("No")
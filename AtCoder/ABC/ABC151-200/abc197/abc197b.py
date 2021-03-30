h, w, x, y = list(map(int, input().split()))
s = [None for i in range(h)]
for i in range(h):
  s[i] = input()

x -= 1
y -= 1
ans = 1

cx = x - 1
while cx >= 0:
  if s[cx][y] == '.':
    ans += 1
  else:
    break
  cx -= 1

cx = x + 1
while cx < h:
  if s[cx][y] == '.':
    ans += 1
  else:
    break
  cx += 1

cy = y - 1
while cy >= 0:
  if s[x][cy] == '.':
    ans += 1
  else:
    break
  cy -= 1

cy = y + 1
while cy < w:
  if s[x][cy] == '.':
    ans += 1
  else:
    break
  cy += 1

print(ans)

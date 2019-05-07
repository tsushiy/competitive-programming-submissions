li = []
for i in range(1, 151):
  for j in range(1, 151):
    if i<j:
      li.append((i, j, i**2+j**2))
li.sort(key=(lambda x:x[0]))
li.sort(key=(lambda x:x[2]))

while True:
  h, w = map(int, input().split())
  if h==0 and w==0:
    break
  else:
    cur = h**2+w**2
    for i in range(len(li)):
      if li[i][2] == cur and li[i][0] == h and li[i][1] == w:
        print(li[i+1][0], li[i+1][1])
        break

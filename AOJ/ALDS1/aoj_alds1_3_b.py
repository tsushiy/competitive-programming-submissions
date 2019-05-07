from collections import deque
n, q = list(map(int, input().split()))
que = deque([])
for i in range(n):
  n, t = input().split()
  que.append((n, t))

e = 0
while len(que)>0:
  n, t = que.popleft()
  if int(t)<=q:
    e += int(t)
    print(n, e)
  else:
    e += q
    que.append((n, int(t)-q))
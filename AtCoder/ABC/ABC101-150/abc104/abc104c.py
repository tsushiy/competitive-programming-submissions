d, g = list(map(int, input().split()))
pc = [list(map(int, input().split())) for i in range(d)]
ans = float("INF")

for i in range(2**d):
  num = 0
  score = 0
  for j in range(d):
    if i&(1<<j):
      num += pc[j][0]
      score += (j+1)*100*pc[j][0] + pc[j][1]
  j = d-1
  while score<g and j>=0:
    if i&(1<<j) == 0:
      rem = g-score
      tmax = (j+1)*100*pc[j][0]
      if rem>=tmax:
        num += pc[j][0]
        score += tmax
      else:
        for k in range(1, pc[j][0]):
          num += 1
          score += (j+1)*100
          if score>=g:
            break
    j -= 1
  if score>=g:
    ans = min(ans, num)
print(ans)
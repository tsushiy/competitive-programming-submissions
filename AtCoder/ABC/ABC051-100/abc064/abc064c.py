n = int(input())
a = list(map(int, input().split()))
color = [0 for i in range(9)]
for e in a:
  if e>=3200:
    color[8] += 1
  else:
    color[e//400] += 1
min_ = 0
for e in color[:8]:
  if e:
    min_ += 1
print(max(1, min_), min_+color[8])
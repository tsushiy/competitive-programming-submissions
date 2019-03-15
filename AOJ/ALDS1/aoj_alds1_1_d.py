n = int(input())
min_ = float("INF")
max_ = float("-INF")
for i in range(n):
  r = int(input())
  max_ = max(max_, r-min_)
  min_ = min(min_, r)
print(max_)
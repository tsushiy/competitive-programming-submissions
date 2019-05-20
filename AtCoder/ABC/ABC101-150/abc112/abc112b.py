n, t = list(map(int, input().split()))
ct = [list(map(int, input().split())) for i in range(n)]
ct.sort()
for i in range(n):
  if ct[i][1]<=t:
    print(ct[i][0])
    exit()
print("TLE")
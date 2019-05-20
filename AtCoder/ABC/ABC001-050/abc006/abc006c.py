n, m = list(map(int, input().split()))
for roujin in range(n):
  rem = n-roujin
  remasi = m-roujin*3
  if remasi%2==1 or (remasi-2*rem)%2==1:
    continue
  akachan = (remasi-2*rem)//2
  otona = rem-akachan
  if otona>=0 and akachan>=0:
    print(otona, roujin, akachan)
    exit()
print(-1, -1, -1)
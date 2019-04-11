a = []
for i in range(5):
  a.append(int(input()))
k = int(input())

if a[4]-a[0]<=k:
  print("Yay!")
else:
  print(":(")
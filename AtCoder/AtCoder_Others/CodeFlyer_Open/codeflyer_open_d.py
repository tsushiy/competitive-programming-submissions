n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

aor = 0
bor = 0
for i in range(n):
  aor = aor|a[i]
  bor = bor|b[i]

print(aor, bor)

if aor==bor:
  print("Yes")
else:
  print("No")
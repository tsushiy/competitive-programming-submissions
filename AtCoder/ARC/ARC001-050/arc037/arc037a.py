n = int(input())
m = list(map(int, input().split()))
ans = 0
for ele in m:
  if ele<80:
    ans += 80-ele
print(ans)
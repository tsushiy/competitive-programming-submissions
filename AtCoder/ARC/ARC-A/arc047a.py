n, l = list(map(int, input().split()))
s = input()
t = 1
ans = 0
for ele in s:
  if ele=="+":
    t += 1
  else:
    t -= 1
  if t>l:
    ans += 1
    t = 1
print(ans)
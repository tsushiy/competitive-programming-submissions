n = int(input())
s = list(map(int, input().split()))
q = int(input())
t = list(map(int, input().split()))
ans = 0
for ele in t:
  if ele in s:
    ans += 1
print(ans)
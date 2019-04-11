from itertools import permutations
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ans = 0
for ele in permutations(b):
  ans = max(ans, (a[0]//ele[0])*(a[1]//ele[1])*(a[2]//ele[2]))
print(ans)
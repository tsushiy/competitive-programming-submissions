n = int(input())
a = list(map(int, input().split()))

for i in range(n):
  a[i] -= (i+1)
a.sort()
m1 = a[n//2]
m2 = a[n//2-1]
ans1 = sum([abs(ele-m1) for ele in a])
ans2 = sum([abs(ele-m2) for ele in a])
print(min(ans1, ans2))
a = list(map(int, input().split()))
a[2] -= a[0]
a[4] -= a[0]
a[3] -= a[1]
a[5] -= a[1]
ans = abs(a[2]*a[5]-a[3]*a[4])/2
print(ans)
n, m = list(map(int, input().split()))
ans = abs((n%12+m/60)*30-m*6)
print(min(ans, 360-ans))
h1, m1, h2, m2, k = list(map(int, input().split()))
a = h1*60+m1
b = h2*60+m2
ans = b-a-k
print(max(0, ans))
n = int(input())
a = list(map(int, input().split()))
b = [(a[i], i+1) for i in range(n)]
b.sort()
ans = [b[i][1] for i in range(n)]
print(*ans)
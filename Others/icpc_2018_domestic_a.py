while True:
    n = int(input())
    if n == 0:
        break
    a = list(map(int, input().split()))
    m = sum(a)/len(a)
    ans = 0
    for ele in a:
        if ele<=m:
            ans+=1
    print(ans)

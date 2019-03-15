while True:
    n, m, t, p = map(int, input().split())
    if n==0 and m==0 and t==0 and p==0:
        break

    paper = [[0 for _ in range(2*n+1)] for _ in range(2*m+1)]
    for i in range(1,n+1):
        for j in range(1,m+1):
            paper[j][i] = 1

    w = n
    h = m
    for _ in range(t):
        d, c = map(int, input().split())
        if d == 1:
            if w-c<c:
                w -= c
                dxx = c - w
                new_paper = [[0 for _ in range(2*n+1)] for _ in range(2*m+1)]
                for i in range(n+1):
                    for j in range(m+1):
                        new_paper[j][i+dxx] = paper[j][i]
                paper = new_paper
                w += dxx
            else:
                w -= c
            for i in range(c):
                for j in range(h+1):
                    paper[j][w-i] += paper[j][w+i+1]
        elif d == 2:
            if h-c <c:
                h -= c
                dyy = c - h
                new_paper = [[0 for _ in range(2*n+1)] for _ in range(2*m+1)]
                for i in range(n+1):
                    for j in range(m+1):
                        new_paper[j+dyy][i] = paper[j][i]
                paper = new_paper
                h += dyy
            else:
                h -= c
            for i in range(c):
                for j in range(w+1):
                    paper[h-i][j] += paper[h+i+1][j]


    for _ in range(p):
        x, y = map(int, input().split())
        print(paper[h-y][w-x])

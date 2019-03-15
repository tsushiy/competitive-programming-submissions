while True:
    n, l, r = map(int, input().split())
    if (n, l, r) == (0, 0, 0):
        break
    else :
        a = []
        count = 0

        for i in range(n):
            a.append(int(input()))

        for i in range(l, r+1):
            flag = 0
            for idx, ele in enumerate(a):
                if i%ele == 0:
                    if (idx+1)%2 == 1:
                        count += 1
                    flag = 1
                    break
            if n%2==0 and flag == 0:
                count += 1
                # print(i)

        print(count)

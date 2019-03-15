from itertools import accumulate
import bisect
f = [i for i in range(1, 10**7)]
s = list(accumulate(f))

while True:
    b = int(input())
    if b==0:
        break

    flag = 0
    r = bisect.bisect_left(s, b)

    while True:
        ele = s[r]
        if flag==1:
            break
        if ele<b:
            continue
        elif ele==b:
            print(1, r+1)
            flag=1
        elif ele>b:
            l = bisect.bisect_left(s[:r+1], ele-b)
            #print(t)
            if ele-s[l]==b:
                print(l+2, r-l)
                flag=1
        r+=1
    #print(l, r-l+1)

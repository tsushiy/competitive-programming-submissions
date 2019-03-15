from itertools import accumulate
import bisect
f = [i for i in range(1, 10**7)]
#s = list(accumulate(f))

while True:
    b = int(input())
    if b==0:
        break


    r = 1
    l = 1
    s = 1
    while True:
        if s<b:
            r+=1
            s+=r
        elif s==b:
            break
        elif s>b:
            s-=l
            l+=1
    print(l, r-l+1)

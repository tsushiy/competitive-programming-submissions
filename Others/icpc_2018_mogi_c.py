def calc(p):
    if s[0]!="[":
        if s[0]=="a":new=int(p[0])
        elif s[0]=="b":new=int(p[1])
        elif s[0]=="c":new=int(p[2])
        elif s[0]=="d":new=int(p[3])
    else:
        stack = ["["]
        for ele in s[1:]:
            if ele!="]":
                stack.append(ele)
            else:
                second = stack.pop()
                first = stack.pop()
                op = stack.pop()
                if first=="a":first=int(p[0])
                elif first=="b":first=int(p[1])
                elif first=="c":first=int(p[2])
                elif first=="d":first=int(p[3])
                if second=="a":second=int(p[0])
                elif second=="b":second=int(p[1])
                elif second=="c":second=int(p[2])
                elif second=="d":second=int(p[3])
                if op=="+":
                    new = first|second
                elif op=="*":
                    new = first&second
                elif op=="^":
                    new = first^second
                stack.pop()
                stack.append(new)
    return new

while True:
    s = input()
    if s == ".":
        break
    else:
        p = input()
        hash = calc(p)
        cnt = 0
        for i in range(10):
            for j in range(10):
                for k in range(10):
                    for l in range(10):
                        p_ = str(i)+str(j)+str(k)+str(l)
                        hash_ = calc(p_)
                        if hash==hash_:
                            cnt+=1
        print(hash, cnt)

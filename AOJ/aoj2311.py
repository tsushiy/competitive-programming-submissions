squarelist = [input() for i in range(8)]
square = ""
for ele in squarelist:
    square+=ele
square=list(square)

def return_reverse_count(idx, turn):
    revcnt = 0
    revlist = []
    if turn=="o":
        revturn = "x"
    else:
        revturn = "o"

    if square[idx] == "o" or square[idx] == "x":
        return -1, []

    #上
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx-8*d
        if 0<=next<=63:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #左
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx-d
        if 0<=next<=63 and idx%8!=0 and next%8>=0:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #右
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx+d
        if 0<=next<=63 and idx%8!=7 and next%8<=7:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #下
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx+8*d
        if 0<=next<=63:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #左上
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx-9*d
        if 0<=next<=63 and idx%8!=0 and idx%8>next%8:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #右上
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx-7*d
        if 0<=next<=63 and idx%8!=7 and idx%8<next%8:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #左下
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx+7*d
        if 0<=next<=63 and idx%8!=0 and idx%8>next%8:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    #右下
    revt = 0
    revflag = 0
    revlist_ = []
    for d in range(1, 8):
        next = idx+9*d
        if 0<=next<=63 and idx%8!=7 and idx%8<next%8:
            if square[next]==turn and revflag==0:
                break
            elif square[next]==turn and revflag==1:
                revcnt+=revt
                revlist.extend(revlist_)
                break
            elif square[next]==".":
                break
            elif square[next]==revturn:
                revt+=1
                revlist_.append(next)
                revflag=1
        else:
            break

    if revcnt == 0:
        return -1, []
    else:
        return revcnt, revlist

turn = "o"
endcnt = 0
while endcnt<2:
    putpos = -1
    putcnt = 0
    returnlist=[]
    for i in range(64):
        revcnt, revlist = return_reverse_count(i, turn)
        if revcnt>putcnt and turn=="o":
            putcnt=revcnt
            putpos=i
            returnlist = revlist
        elif revcnt>=putcnt and turn=="x":
            putcnt=revcnt
            putpos=i
            returnlist = revlist
    if putpos == -1:
        endcnt+=1
    else:
        square[putpos] = turn
        for idx in returnlist:
            square[idx] = turn
        endcnt=0

    if turn=="o":
        turn="x"
    else:
        turn="o"


for i in range(8):
    str = "".join(square[i*8:i*8+8])
    print(str)

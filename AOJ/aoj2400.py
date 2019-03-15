while True:
  t, p, r = map(int, input().split())

  if t==0 and p==0 and r==0:
    break
  else:
    tlist = [[0]*(3+p) for i in range(t)]

    for i in range(t):
      tlist[i][0] = i+1
    for _ in range(r):
      tid, pid, time, message = input().split()
      tid = int(tid)
      pid = int(pid)
      time = int(time)

    if message == "WRONG":
      tlist[tid-1][3+pid-1]+=1
    else:
      tlist[tid-1][1]+=1
      wa = tlist[tid-1][3+pid-1]
      tlist[tid-1][2] = tlist[tid-1][2]+wa*1200+time

  from operator import itemgetter
  tlist.sort(key=itemgetter(2))
  tlist.sort(key=itemgetter(1), reverse=True)

  for i in range(len(tlist)):
    print(tlist[i][0], tlist[i][1], tlist[i][2])

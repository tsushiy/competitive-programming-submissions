while True:
  n = int(input())
  if n==0:
    break
  else:
    ans = []
    for i in range(n):
      list = input().split()
      list[1:] = [int(ele) for ele in list[1:]]

      t = sum(list[2:5]) + sum(list[5:7])*list[-1]
      p = list[-3]*list[-2]*list[-1]-list[1]

      ans.append((p/t, list[0]))

    from operator import itemgetter
    ans.sort(key=itemgetter(1))
    ans.sort(key=itemgetter(0), reverse=True)

    for _, j in ans:
      print(j)
    print("#")

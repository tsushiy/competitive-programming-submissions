while True:
  n  = int(input())
  if n == 0:
    break
  else:
    # 桁を決める
    l = 1
    sum_ = 0
    while sum_ < n:
      sum_ += (9*9*(2**(l-1)-1))
      l += 1
    l -= 1
    sum_ -= (9*9*(2**(l-1)-1))

    # 最初の数字を決める
    for i in range(1, 10):
      sum_ += 9*(2**(l-1)-1)
      if sum_ >= n:
        dfirst = i
        sum_ -= 9*(2**(l-1)-1)
        break
    
    # dfirstの連続する桁数を求める
    c = 1
    dsecond = 0
    for i in range(1, l+1):
      if sum_+(dfirst*(2**(l-i-1))) < n <= sum_+(dfirst*(2**(l-i-1)))+9*(2**(l-i-1)-1):
        c+=1
        sum_ += dfirst*(2**(l-i-1))
      elif n <= sum_+(dfirst*(2**(l-i-1))):
        for j in range(0, dfirst):
          sum_ += (2**(l-i-1))
          if sum_ >= n:
            dsecond = j
            sum_ -= (2**(l-i-1))
            break
        break
      elif sum_+(dfirst*(2**(l-i-1)))+9*(2**(l-i-1)-1) < n:
        sum_ += (dfirst*(2**(l-i-1)))+9*(2**(l-i-1)-1)
        for j in range(dfirst+1, 10):
          sum_ += (2**(l-i-1))
          if sum_ >= n:
            dsecond = j
            sum_ -= (2**(l-i-1))
            break
        break

    # 残りのL-C-1桁を求める
    dhigh = max(dfirst, dsecond)
    dlow = min(dfirst, dsecond)
    str_ = ""
    if (n-sum_-1) == 0:
      str_=str(dlow)*(l-c-1)
    else:
      bin_ = bin(n-sum_-1)
      bin_ = bin_[2:].zfill(l-c-1)
      for ele in bin_:
        if ele == "1":
          str_ += str(dhigh)
        else:
          str_ += str(dlow)

    #print(l, c, dfirst, dsecond, n-sum_-1)
    print(str(dfirst)*c+str(dsecond)+str_)
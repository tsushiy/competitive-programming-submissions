s = input()
a, b, c, d = s[0], s[1], s[2], s[3]
for op1 in "+-":
  for op2 in "+-":
    for op3 in "+-":
      f = a+op1+b+op2+c+op3+d
      if eval(f)==7:
        print(f+"=7")
        exit()
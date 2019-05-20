import string
abc = string.ascii_uppercase

while True:
  s = input()
  if s==".":
    break

  num = 0
  rev = 0
  nest = ["" for i in range(80)]

  for e in s:
    if e=="+":
      num += 1
    elif e=="-":
      num -= 1
    elif e=="[":
      rev += 1
    elif e=="]":
      t = nest[rev]
      nest[rev-1] += t[::-1]
      nest[rev] = ""
      rev -= 1
    elif e=="?":
      nest[rev] += "A"
      num = 0
    else:
      t = abc[(ord(e)+num-65)%26]
      nest[rev] += t
      num = 0
  print(nest[0])
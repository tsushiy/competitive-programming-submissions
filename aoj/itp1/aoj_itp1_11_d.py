class Dice:
  def __init__(self, top=1, front=2, left=4, right=3, back=5, bottom=6):
    self.d = {"TOP":top, "FRONT":front, "LEFT":left, "RIGHT":right, "BACK":back, "BOTTOM":bottom}

  def roll_x(self):
    self._roll("TOP", "FRONT", "BOTTOM", "BACK")
  
  def roll_y(self):
    self._roll("FRONT", "LEFT", "BACK", "RIGHT")
  
  def roll_z(self):
    self._roll("TOP", "LEFT", "BOTTOM", "RIGHT")
  
  def _roll(self, a, b, c, d):
    self.d[a], self.d[b], self.d[c], self.d[d] = \
    self.d[b], self.d[c], self.d[d], self.d[a]
  
  def all_rolls(self):
    ret = []
    for i in range(6):
      if i%2:
        self.roll_x()
      else:
        self.roll_y()
      for _ in range(4):
        self.roll_z()
        t = self.d.copy()
        ret.append(t)
    return ret

  def equivalent(self, dice):
    for i in range(6):
      if i%2:
        self.roll_x()
      else:
        self.roll_y()
      for _ in range(4):
        self.roll_z()
        t = self.d.copy()
        if t==dice.d:
          return True
    return False

n = int(input())
d = []
flag = False
for i in range(n):
  a = list(map(int, input().split()))
  d.append(Dice(a[0], a[1], a[3], a[2], a[4], a[5]))
for i in range(n):
  for j in range(i+1, n):
    if d[i].equivalent(d[j]):
      flag = True
      break
if flag:
  print("No")
else:
  print("Yes")
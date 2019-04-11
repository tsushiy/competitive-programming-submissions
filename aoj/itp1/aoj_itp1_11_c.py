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

d1 = list(map(int, input().split()))
dd1 = Dice(d1[0], d1[1], d1[3], d1[2], d1[4], d1[5])
d2 = list(map(int, input().split()))
dd2 = Dice(d2[0], d2[1], d2[3], d2[2], d2[4], d2[5])
if dd1.equivalent(dd2):
  print("Yes")
else:
  print("No")
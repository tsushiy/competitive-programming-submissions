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

d = list(map(int, input().split()))
q = input()
dd = Dice(d[0], d[1], d[3], d[2], d[4], d[5])
for ele in q:
  if ele=="N":
    dd.roll_x()
  elif ele=="S":
    for _ in range(3):
      dd.roll_x()
  elif ele=="E":
    dd.roll_z()
  elif ele=="W":
    for _ in range(3):
      dd.roll_z()
print(dd.d["TOP"])
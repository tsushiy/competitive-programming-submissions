sx, sy, tx, ty = list(map(int, input().split()))
ans1 = "U"*(ty-sy)+"R"*(tx-sx)+"D"*(ty-sy)+"L"*(tx-sx)
ans2 = "L"+"U"*(ty-sy+1)+"R"*(tx-sx+1)+"D"+"R"+"D"*(ty-sy+1)+"L"*(tx-sx+1)+"U"
print(ans1+ans2)
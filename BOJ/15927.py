a = str(input())
if a != a[::-1] : print(len(a))
else :
    fl = 1
    for i in a :
        if i != a[0] : fl = 0
    if fl : print(-1)
    else : print(len(a)-1)

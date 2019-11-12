a = int(input())
l = 1
r = 10**400
while l <= r :
    mid = (l+r)//2
    if a//mid < mid : r = mid-1;
    elif a//mid > mid : l = mid+1;
    else :
        l = mid
        break
print(l)

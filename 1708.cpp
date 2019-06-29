#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    ll x,y;
    bool operator < (const Point &a)const{
        return tie(x,y) < tie(a.x,a.y);
    }
    Point operator - (const Point &a)const{
        return {x-a.x,y-a.y};
    }
}in[101010],st[101010];
int n,k;
ll cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld %lld",&in[i].x,&in[i].y);
    int it = min_element(in+1,in+n+1) - in;
    swap(in[1],in[it]);
    sort(in+2,in+n+1,[&](Point &a,Point &b){
        int re = cross(a-in[1],b-in[1]);
        return re ? re > 0 : a < b;
    });
    for(int i=1;i<=n;i++){
        while(k>=2 && cross(st[k]-st[k-1],in[i]-st[k-1]) <= 0) k--;
        st[++k] = in[i];
    }
    printf("%d",k);
}

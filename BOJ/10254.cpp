#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    ll x,y;
    bool operator < (const Point &a)const{
        return tie(x,y) < tie(a.x,a.y);
    }
    Point operator - (const Point &a) const{
        return {x-a.x,y-a.y};
    }
}in[202020],st[202020];
ll cross(Point o,Point a,Point b){
    a = a-o;
    b = b-o;
    return a.x*b.y-a.y*b.x;
}
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        int k = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld %lld",&in[i].x,&in[i].y);
        if(n <= 3){}
        int it = min_element(in+1,in+1+n) - in;
        swap(in[1], in[it]);
        sort(in+2,in+n+1,[&](Point &a,Point &b){
                ll re = cross(in[1], a, b);
                return re ? re > 0 : a < b;
        });
        for(int i=1;i<=n;i++){
            while(k >= 2 && cross(st[k-1],st[k],in[i]) <= 0) k--;
            st[++k] = in[i];
        }

        if(k <= 2) printf("%lld %lld %lld %lld\n",st[1].x,st[1].y,st[2].x,st[2].y);
        else{
            int r = 2;
            ll dis = 0, x[2], y[2];
            Point O = {0,0};
            for(int i=1;i<=k;i++){
                while(cross(O,st[i%k+1]-st[i],st[r%k+1]-st[r]) > 0) r=r%k+1;
                printf("%d %d\n",i,r);
                if(dis < (st[i].x-st[r].x)*(st[i].x-st[r].x)+(st[i].y-st[r].y)*(st[i].y-st[r].y)){
                    dis = (st[i].x-st[r].x)*(st[i].x-st[r].x)+(st[i].y-st[r].y)*(st[i].y-st[r].y);
                    x[0] = st[i].x;
                    y[0] = st[i].y;
                    x[1] = st[r].x;
                    y[1] = st[r].y;
                }
            }
            printf("%lld %lld %lld %lld\n",x[0],y[0],x[1],y[1]);
        }
    }
}

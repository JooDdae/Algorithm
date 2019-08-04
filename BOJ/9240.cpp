#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point{
    int x,y;
    bool operator < (const Point &a)const{
        return tie(x,y) < tie(a.x,a.y);
    }
    Point operator - (const Point &a)const{
        return {x-a.x,y-a.y};
    }
}in[101010],st[101010];
int n,k;
double ans;
int cross(Point a,Point b){
    return a.x*b.y-a.y*b.x;
}
double dist(Point a,Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&in[i].x,&in[i].y);
    int it = min_element(in+1,in+1+n) - in;
    swap(in[1],in[it]);
    sort(in+2,in+n+1,[&](Point &a,Point &b){
        ll re = cross(a-in[1],b-in[1]);
        return re ? re > 0 :  a < b;
    });
    for(int i=1;i<=n;i++){
        while(k>=2 && cross(st[k]-st[k-1],in[i]-st[k-1]) <= 0) k--;
        st[++k] = in[i];
    }

    if(k <= 2) ans = dist(st[1],st[2]);
    else{
        int r = 2;
        for(int i=1;i<=n;i++){
            while(cross(st[i%k+1]-st[i],st[r%k+1]-st[r]) > 0) r=r%k+1;
            ans = max(ans, dist(st[i],st[r]));
        }
    }
    printf("%.8f",ans);
}

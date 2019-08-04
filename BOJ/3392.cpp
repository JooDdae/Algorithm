#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
    int y,x,xx,t;
    bool operator < (const point &a)const{
        return y>a.y;
    }
};
int n,x[10101][2],y[10101][2],ans,tree[121212],sz[121212];
priority_queue<point> pq;
void up(int node,int l,int r,int nl,int nr,int val){
    if(r<nl || nr<l) return;
    if(nl<=l && r<=nr) sz[node] += val;
    else{
        up(node*2,l,(l+r)/2,nl,nr,val);
        up(node*2+1,(l+r)/2+1,r,nl,nr,val);
    }
    if(sz[node]) tree[node] = r-l+1;
    else{
        if(l == r) tree[node] = 0;
        else tree[node] = tree[node*2] + tree[node*2+1];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) scanf("%d %d",&x[i][j],&y[i][j]);
    for(int i=1;i<=n;i++){
        pq.push({y[i][0],x[i][0],x[i][1]-1,1});
        pq.push({y[i][1],x[i][0],x[i][1]-1,-1});
    }
    int ly=0;
    while(!pq.empty()){
        int cur = pq.top().y;
        ans += (cur-ly)*tree[1];
        while(!pq.empty() && pq.top().y == cur){
            up(1,0,30000,pq.top().x,pq.top().xx,pq.top().t);
            pq.pop();
        }
        ly = cur;
    }
    printf("%d",ans);
}

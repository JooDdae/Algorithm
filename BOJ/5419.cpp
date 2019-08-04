#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct point{
    int x,y;
    bool operator < (const point &a)const{
        return tie(x,a.y) < tie(a.x,y);
    }
}p[80808];
int t,n,cx[80808],cy[80808],tree[323232];
priority_queue<pii,vector<pii>,greater<pii>> pq;
void up(int node,int l,int r,int id){
    if(id<l || r<id) return;
    if(l==r){
        tree[node]++;
        return;
    }
    up(node*2,l,(l+r)/2,id);
    up(node*2+1,(l+r)/2+1,r,id);
    tree[node] = tree[node*2]+tree[node*2+1];
}
int f(int node,int l,int r,int nl,int nr){
    if(nr<l || r<nl) return 0;
    if(nl<=l && r<=nr) return tree[node];
    return f(node*2,l,(l+r)/2,nl,nr) + f(node*2+1,(l+r)/2+1,r,nl,nr);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d %d",&p[i].x,&p[i].y);
        int num = 0,l = -1e9-1;
        for(int i=1;i<=n;i++) pq.push({p[i].y,i});
        while(!pq.empty()){
            if(l != pq.top().first) num++;
            l = pq.top().first;
            p[pq.top().second].y = num;
            pq.pop();
        }
        sort(p+1,p+1+n);

        ll ans = 0;
        for(int i=1;i<=n;i++){
            ans += f(1,1,num,p[i].y,num);
            up(1,1,num,p[i].y);
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n*4;i++) tree[i] = 0;
    }
}

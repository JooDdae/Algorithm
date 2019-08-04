#include<bits/stdc++.h>
using namespace std;
struct node{
    int s,e,dis;
    bool operator < (const node &a)const{
        return dis<a.dis;
    }
};
int n,m,par[1010],ans;
priority_queue<node> pq;
int f(int a){
    if(a == par[a]) return a;
    return par[a] = f(par[a]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        pq.push({a,b,c});
    }
    while(!pq.empty()){
        int a=f(pq.top().s),b=f(pq.top().e),c=pq.top().dis;
        pq.pop();

        if(a == b) continue;
        ans += c;
        par[a] = b;
    }
    for(int i=2;i<=n;i++) if(par[f(i)] != par[f(1)]) return !printf("-1");
    printf("%d",ans);
}

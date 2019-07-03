#include <bits/stdc++.h>
using namespace std;
struct node{
    int hp,f,s,num;
    bool operator < (const node &a)const{
        return hp > a.hp;
    }
}in[252525];
int n,q,par[252525],ans[252525];
pair<int,int> x[252525],y[252525];
priority_queue<node> pq;
int f(int a){
    if(a == par[a]) return a;
    return par[a] = f(par[a]);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d %d",&x[i].first,&y[i].first);
    for(int i=1;i<=n;i++) x[i].second = y[i].second = i;
    for(int i=1;i<=n;i++) par[i] = i;
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    for(int i=2;i<=n;i++) pq.push({x[i].first-x[i-1].first,x[i].second,x[i-1].second,0});
    for(int i=2;i<=n;i++) pq.push({y[i].first-y[i-1].first,y[i].second,y[i-1].second,0});
    for(int i=1;i<=q;i++) scanf("%d %d %d",&in[i].f,&in[i].s,&in[i].hp);
    for(int i=1;i<=q;i++) in[i].hp = -in[i].hp;
    for(int i=1;i<=q;i++) in[i].num = i;
    sort(in+1,in+1+q);
    int cur = 1;
    while(!pq.empty()){
        while(pq.top().hp > -in[cur].hp && cur <= q){
            ans[in[cur].num] = f(in[cur].f) == f(in[cur].s);
            cur++;
        }
        int x=pq.top().f, y=pq.top().s;
        pq.pop();
        par[f(x)] = f(y);
    }
    while(cur <= q){
        ans[in[cur].num] = f(in[cur].f) == f(in[cur].s);
        cur++;
    }
    for(int i=1;i<=q;i++) puts(ans[i]?"YES":"NO");
}

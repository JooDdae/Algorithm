#include<bits/stdc++.h>
using namespace std;
const int c[5][5]={
    {10,8,7,5,1},
    {8,6,4,3,1},
    {7,4,3,2,1},
    {5,3,2,2,1},
    {1,1,1,1,0}
},dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},sink=3000,INF=1e9;
struct node{
    int to, from, cost, cap, val, rev;
}*back[3030];
int n,m,ans,vis[3030],dist[3030];
char s[55][55];
vector<node> v[3030];
queue<int> q;
int MCMF(){
    for(int i=1;i<=3000;i++) dist[i] = INF;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        vis[cur] = 0;
        for(auto &nxt : v[cur]){
            if(nxt.cap - nxt.val <= 0) continue;
            if(dist[nxt.to] > dist[cur] + nxt.cost){
                dist[nxt.to] = dist[cur] + nxt.cost;
                back[nxt.to] = &nxt;
                if(!vis[nxt.to]) q.push(nxt.to), vis[nxt.to] = 1;
            }
        }
    }
    if(dist[sink] == INF) return 0;
    int cur = sink;
    while(cur){
        back[cur]->val++;
        v[back[cur]->to][back[cur]->rev].val--;
        cur = back[cur]->from;
    }
    return dist[sink];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j] -= 'A' + (s[i][j] == 'F');
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if((i+j)%2){
        int cur = i*55 + j;
        v[cur].push_back({sink, cur, 0, 1, 0, v[sink].size()});
        v[sink].push_back({cur, sink, 0, 0, 0, v[cur].size()-1});
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if((i+j)%2 == 0){
        int cur = i*55 + j;
        v[0].push_back({cur, 0, 0, 1, 0, v[cur].size()});
        v[cur].push_back({0, cur, 0, 0, 0, v[0].size()-1});
        v[cur].push_back({sink, cur, 0, 1, 0, v[sink].size()});
        v[sink].push_back({cur, sink, 0, 0, 0, v[cur].size()-1});
        for(int d=0;d<4;d++){
            int x = i+dx[d], y = j+dy[d];
            if(x<1 || y<1 || x>n || y>m) continue;
            int nxt = x*55 + y;
            v[cur].push_back({nxt, cur, -c[s[i][j]][s[x][y]], 1, 0, v[nxt].size()});
            v[nxt].push_back({cur, nxt, c[s[i][j]][s[x][y]], 0, 0, v[cur].size()-1});
        }
    }
    while(1){
        int p = MCMF();
        if(!p) break;
        ans += p;
    }
    printf("%d",-ans);
}
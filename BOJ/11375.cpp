//boj.kr/2188
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1010
#define MAX_M 1010

int vis[MAX_N], used[MAX_N], match[MAX_M], dist[MAX_N], n, m, ans;
queue<int> q;
vector<int> v[MAX_N];

void bfs(){
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto e : v[u]){
            if(match[e] && !dist[match[e]]){
                dist[match[e]] = dist[u]+1;
                q.push(match[e]);
            }
        }
    }
}

int dfs(int u){
    vis[u] = 1;
    for(auto e : v[u]){
        if(!match[e] || (!vis[match[e]] && dist[u]+1 == dist[match[e]] && dfs(match[e]))){
            match[e] = u;
            used[u] = 1;
            return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int a; scanf("%d",&a);
        while(a--){
            int b; scanf("%d",&b);
            v[i].push_back(b);
        }
    }
    while(1){
	    for(int i=1;i<=n;i++) dist[i] = !used[i];
	    for(int i=1;i<=n;i++) if(!used[i]) q.push(i);
        bfs();
        int f = 0;
        for(int i=1;i<=n;i++) vis[i] = 0;
        for(int i=1;i<=n;i++) if(!used[i]) f+=dfs(i);
        if(!f) break;
        ans += f;
    }
    printf("%d",ans);
}
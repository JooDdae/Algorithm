#include<bits/stdc++.h>
using namespace std;
int n,m,vis[1010],used[1010],match[1010],dist[1010],ans;
char s[111];
map<string,int> mp;
vector<int> v[1010];
queue<int> q;

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
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		mp[s] = i;
	}
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		while(a--){
			scanf("%s",s);
			v[i].push_back(mp[s]);
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

	if(ans == n) printf("YES");
	else printf("NO\n%d",ans);
}
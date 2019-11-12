#include<bits/stdc++.h>
using namespace std;
struct node{
	int to, from, cost, cap, val, rev;
}*back[2020];
int n,m,ans,dist[2020],vis[2020],INF=1e9;
vector<node> v[2020];
queue<int> q;

int MCMF(){
	for(int i=1;i<=n+1;i++) dist[i] = INF;
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

	if(dist[n+1] == INF) return 0;
	int cur = n+1;
	while(cur){
		back[cur]->val++;
		v[back[cur]->to][back[cur]->rev].val--;
		cur = back[cur]->from;
	}
	return dist[n+1];
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b, a, c, 1, 0, v[b].size()});
		v[b].push_back({a, b, -c, 0, 0, v[a].size()-1});

		v[b].push_back({a, b, c, 1, 0, v[a].size()});
		v[a].push_back({b, a, -c, 0, 0, v[b].size()-1});
	}
	v[0].push_back({1, 0, 0, 2, 0, v[1].size()});
	v[1].push_back({0, 1, 0, 0, 0, v[0].size()-1});
	v[n].push_back({n+1, n, 0, 2, 0, v[n+1].size()});
	v[n+1].push_back({n, n+1, 0, 0, 0, v[n].size()-1});

	while(1){
		int fl = MCMF();
		if(!fl) break;
		ans += fl;
	}

	printf("%d",ans);
}
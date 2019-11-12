#include<bits/stdc++.h>
using namespace std;
struct node{
	int to, from, cost, cap, val, rev;
}*back[1010];
int n,m,k,dist[1010],vis[1010],INF=1e9;
vector<node> v[1010];
queue<int> q;

pair<int,int> MCMF(){
	for(int i=1;i<=n+3;i++) dist[i] = INF;
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
	if(dist[n+3] == INF) return {0,0};
	int cur = n+3, flow = INF;
	while(cur){
		flow = min(flow, back[cur]->cap - back[cur]->val);
		cur = back[cur]->from;
	}
	cur = n+3;
	while(cur){
		back[cur]->val += flow;
		v[back[cur]->to][back[cur]->rev].val -= flow;
		cur = back[cur]->from;
	}
	return {flow, dist[n+3]};
}

int main(){
	while(1){
		scanf("%d %d %d",&n,&m,&k);
		if(!n && !m && !k) break;
		v[n+1].push_back({n+3, n+1, 0, m, 0, v[n+3].size()});
		v[n+3].push_back({n+1, n+3, 0, 0, 0, v[n+1].size()-1});
		v[n+2].push_back({n+3, n+2, 0, k, 0, v[n+3].size()});
		v[n+3].push_back({n+2, n+3, 0, 0, 0, v[n+2].size()-1});
		for(int i=1;i<=n;i++){
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			v[0].push_back({i, 0, 0, a, 0, v[i].size()});
			v[i].push_back({0, i, 0, 0, 0, v[0].size()-1});

			v[i].push_back({n+1, i, b, INF, 0, v[n+1].size()});
			v[n+1].push_back({i, n+1, -b, 0, 0, v[i].size()-1});

			v[i].push_back({n+2, i, c, INF, 0, v[n+2].size()});
			v[n+2].push_back({i, n+2, -c, 0, 0, v[i].size()-1});
		}

		int ans = 0;
		while(1){
			pair<int,int> p = MCMF();
			if(!p.first) break;
			ans += p.first * p.second;
		}
		printf("%d\n",ans);

		for(int i=0;i<=n+3;i++) v[i].clear();
	}
}
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 404

struct node{
	int to, cap, flow, rev;
};
int n, m, ans, source, sink, lev[MAX_N], used[MAX_N], INF=1e9;
vector<node> v[MAX_N];

void addEdge(int l,int r,int cap){
	v[l].push_back({r, cap, 0, v[r].size()});
	v[r].push_back({l, 0, 0, v[l].size()-1});
}

bool bfs(){
	for(int i=1;i<=n;i++) lev[i] = -1;
	lev[source] = 0;

	queue<int> q;
	q.push(source);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for(auto nxt : v[cur]){
			if(lev[nxt.to] == -1 && nxt.cap != nxt.flow){
				lev[nxt.to] = lev[cur] + 1;
				q.push(nxt.to);
			}
		}
	}

	return lev[sink] != -1;
}

int dfs(int cur, int flow){
	if(cur == sink) return flow;

	for(int &i = used[cur]; i<v[cur].size(); i++){
		node &nxt = v[cur][i];
		if(lev[cur] + 1 == lev[nxt.to] && nxt.cap != nxt.flow){
			int f = dfs(nxt.to, min(flow, nxt.cap - nxt.flow));
			if(f){
				nxt.flow += f;
				v[nxt.to][nxt.rev].flow -= f;
				return f;
			}
		}
	}

	return 0;
}

int main(){
	scanf("%d %d",&n,&m);
	source = 1, sink = 2;
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		addEdge(a, b, 1);
	}
	while(bfs()){
		for(int i=1;i<=n;i++) used[i] = 0;
		while(1){
			int flow = dfs(source, INF);
			if(!flow) break;
			ans += flow;
		}
	}
	printf("%d",ans);
}
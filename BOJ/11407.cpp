#include<bits/stdc++.h>
using namespace std;

#define MAX_N 101
#define MAX_M 101

const int INF = 1e9;
struct node{
	int to,from,cost,cap,val,rev;
}*back[MAX_N + MAX_M];
int n,m,ans[2],c[MAX_N][MAX_M],vis[MAX_N + MAX_M],dist[MAX_N + MAX_M],source,sink;
vector<node> v[MAX_N + MAX_M];
queue<int> q;

void addEdge(int l,int r,int cost,int flow){
	v[l].push_back({r, l, cost, flow, 0, v[r].size()});
	v[r].push_back({l, r, -cost, 0, 0, v[l].size()-1});
}

pair<int,int> MCMF(){
	for(int i=1;i<=sink;i++) dist[i] = INF;
	q.push(source);
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
	int cur = sink, flow = INF;
	while(cur != source){
		flow = min(flow, back[cur]->cap - back[cur]->val);
		cur = back[cur]->from;
	}
	cur = sink;
	while(cur != source){
		back[cur]->val += flow;
		v[back[cur]->to][back[cur]->rev].val -= flow;
		cur = back[cur]->from;
	}
	return {flow, dist[sink]};
}

int main(){
	scanf("%d %d",&n,&m);
	source = 0, sink = n+m+1;
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		addEdge(source, i, 0, a);
	}
	for(int i=1;i<=m;i++){
		int a; scanf("%d",&a);
		addEdge(i+n, sink, 0, a);
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",&c[i][j]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int a; scanf("%d",&a);
			if(c[i][j]) addEdge(j, i+n, a, c[i][j]);
		}
	}

	while(1){
		pair<int,int> p = MCMF();
		if(!p.first) break;
		ans[0] += p.first;
		ans[1] += p.first * p.second;
	}

	printf("%d\n%d",ans[0],ans[1]);
}
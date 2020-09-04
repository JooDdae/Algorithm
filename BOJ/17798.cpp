#include<bits/stdc++.h>
using namespace std;

#define MAX_N 200
#define MAX_M 200

const int INF = 1e9;
struct node{
	int to,from,cost,cap,val,rev;
}*back[MAX_N + MAX_M];
int n,m,ans[2],vis[MAX_N + MAX_M],dist[MAX_N + MAX_M],source,sink;
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
	if(dist[sink] == INF) return {0,0};
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
	source = 0, sink = n+n+1;
	for(int i=1;i<=n;i++) addEdge(source, i, 0, 1), addEdge(i, n+i, 0, 1), addEdge(n+i, sink, 0, 1);
	for(int i=1;i<=m;i++){
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		addEdge(a, n+b, -c, 1);
	}
	while(1){
		pair<int,int> p = MCMF();
		if(!p.first) break;
		ans[0] += p.first;
		ans[1] += p.second;
	}
	printf("%.10f",-(double)ans[1]/20);
}
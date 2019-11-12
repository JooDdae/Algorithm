#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,from,cost,cap,val,rev;
}*back[1010];
const int INF = 1e9;
int n,m,ans[2],vis[1010],dist[1010],source,sink;
vector<node> v[1010];
queue<int> q;
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
	int cur = sink, fl = INF;
	while(cur != source){
		fl = min(fl, back[cur]->cap - back[cur]->val);
		cur = back[cur]->from;
	}
	cur = sink;
	while(cur != source){
		back[cur]->val += fl;
		v[back[cur]->to][back[cur]->rev].val -= fl;
		cur = back[cur]->from;
	}
	return {fl, dist[sink]};
}
int main(){
	scanf("%d %d",&n,&m);
	source = 0, sink = n+m+1;
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		v[source].push_back({i, source, 0, 1, 0, v[i].size()});
		v[i].push_back({source, i, 0, 0, 0, v[source].size()-1});
		while(a--){
			int b,c; scanf("%d %d",&b,&c);
			v[i].push_back({n+b, i, c, 1, 0, v[n+b].size()});
			v[n+b].push_back({i, n+b, -c, 0, 0, v[i].size()-1});
		}
	}
	for(int i=n+1;i<=n+m;i++){
		v[i].push_back({sink, i, 0, 1, 0, v[sink].size()});
		v[sink].push_back({i, sink, 0, 0, 0, v[i].size()-1});
	}
	while(1){
		pair<int,int> p = MCMF();
		if(!p.first) break;
		ans[0] += p.first;
		ans[1] += p.second;
	}
	printf("%d\n%d",ans[0],ans[1]);
}
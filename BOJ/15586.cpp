#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct node{
	int s, e, v;
	bool operator < (const node &a) const{
		return v < a.v;
	}
};
struct query{
	int s, e, id;
	bool operator < (const query &a) const{
		return s > a.s;
	}
}q[100100];
int n, m, par[100100], sz[100100], ans[100100];
priority_queue<node> pq;
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
void merge(int a, int b, ll c){
	a = f(a), b = f(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[b] += sz[a];
	par[a] = b;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) par[i] = i, sz[i] = 1;
	for(int i=1;i<n;i++){
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		pq.push({a, b, c});
	}
	for(int i=1;i<=m;i++) scanf("%d %d",&q[i].s,&q[i].e), q[i].id = i;
	sort(q+1, q+1+m);
	int u = 1;
	while(!pq.empty()){
		int s = pq.top().s, e = pq.top().e, v = pq.top().v; pq.pop();
		while(u <= m && v < q[u].s) ans[q[u].id] = sz[f(q[u].e)], u++;
		merge(s, e, v);
	}
	while(u <= m) ans[q[u].id] = sz[f(q[u].e)], u++;
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]-1);
}
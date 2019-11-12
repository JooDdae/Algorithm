#include<bits/stdc++.h>
using namespace std;

#define MAX_N 808

struct node{
	int to,cap,val,r;
};
int n,m,ans,chk[MAX_N],source,sink;
vector<node> v[MAX_N];

void addEdge(int l,int r,int cap){
	v[l].push_back({r, cap, 0, v[r].size()});
	v[r].push_back({l, 0, 0, v[l].size()-1});
}

int f(int cur,int cap){
	if(cur == sink) return cap;
	chk[cur] = 1;
	for(node &e : v[cur]){
		if(chk[e.to] || e.val == e.cap) continue;
		int fl = f(e.to, min(cap, e.cap-e.val));
		if(fl){
			e.val += fl;
			v[e.to][e.r].val -= fl;
			return fl;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&m);
	source = 1, sink = 2+n;
	for(int i=1;i<=n;i++) addEdge(i+n, i, 1);
	for(int i=1;i<=n;i++) addEdge(i, i+n, 1);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		addEdge(a, b+n, 1e9);
		addEdge(b, a+n, 1e9);
	}
	while(1){
		int fl = f(source,1e9);
		if(!fl) break;
		ans += fl;
		for(int i=1;i<=n+n;i++) chk[i]=0;
	}
	printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cap,val,r;
};
int n,m,chk[222],ans;
vector<node> v[222];
int f(int cur,int cap){
	if(cur == n+n+2) return cap;
	chk[cur] = 1;
	for(node &e : v[cur]){
		if(chk[e.to] || e.val == e.cap) continue;
		int fl=f(e.to,min(cap, e.cap-e.val));
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
	while(m--){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back({n+b,1,0,v[n+b].size()});
		v[n+b].push_back({a,0,0,v[a].size()-1});
	}
	for(int i=1;i<=n;i++){
		v[n+n+1].push_back({i,1,0,v[i].size()});
		v[i].push_back({n+n+1,0,0,v[n+n+1].size()-1});
	}
	for(int i=1;i<=n;i++){
		v[i+n].push_back({n+n+2,1,0,v[n+n+2].size()});
		v[n+n+2].push_back({i+n,0,0,v[i+n].size()-1});
	}
	while(1){
		int fl=f(n+n+1,1e9);
		if(!fl) break;
		ans+=fl;
		for(int i=1;i<=n+n+1;i++) chk[i]=0;
	}
	printf("%d",ans);
}
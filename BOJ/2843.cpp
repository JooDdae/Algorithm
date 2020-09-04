#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, to[300300], chk[300300], par[300300], cycle[300300], x[300300], y[300300];
vector<int> ans;
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
void merge(int a, int b){
	b = f(b);
	if(a == b) cycle[b] = 1;
	par[a] = b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",to+i);
	for(int i=1;i<=n;i++) par[i] = i;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",x+i,y+i);
		if(x[i] == 2) chk[y[i]] = 1;
	}
	for(int i=1;i<=n;i++) if(!chk[i] && to[i]) merge(i, to[i]);

	for(int i=m;i>=1;i--){
		if(x[i] == 1){
			int u = f(y[i]);
			if(cycle[u]) ans.push_back(0);
			else ans.push_back(u);
		}else merge(y[i], to[y[i]]);
	}
	reverse(ans.begin(), ans.end());
	for(auto x : ans){
		if(!x) puts("CIKLUS");
		else printf("%d\n",x);
	}
}
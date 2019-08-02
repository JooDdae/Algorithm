#include<bits/stdc++.h>
using namespace std;
int n,sp[20][50505],lev[50505],q;
vector<int> v[50505];
void dfs(int cur,int par){
	sp[0][cur]=par; lev[cur]=lev[par]+1;
	for(int nxt : v[cur]) if(nxt!=par) dfs(nxt, cur);
}
int lca(int a,int b){
	if(lev[a]>lev[b]) swap(a,b);
	int g = lev[b]-lev[a];
	for(int i=0;i<=18;i++) if((1<<i)&g) b=sp[i][b];
	if(a==b) return a;
	for(int i=18;i>=0;i--) if(sp[i][a] != sp[i][b]) a=sp[i][a],b=sp[i][b];
	return sp[0][a];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=18;i++) for(int j=1;j<=n;j++) sp[i][j]=sp[i-1][sp[i-1][j]];
	scanf("%d",&q);
	while(q--){
		int a,b; scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
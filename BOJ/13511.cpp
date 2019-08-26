#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,sp[18][101010],lev[101010];
ll dist[18][101010];
vector<pair<int,int>> v[101010];
void dfs(int cur,int par,int cost){
	lev[cur] = lev[par]+1;
	sp[0][cur] = par;
	dist[0][cur] = cost;
	for(auto nxt : v[cur]) if(nxt.first != par) dfs(nxt.first, cur, nxt.second);
}
ll lca1(int a,int b){
	if(lev[a] < lev[b]) swap(a,b);
	ll re=0;
	for(int i=17;i>=0;i--) if((lev[a]-lev[b])&(1<<i)) re += dist[i][a], a = sp[i][a];
	if(a == b) return re;
	for(int i=17;i>=0;i--) if(sp[i][a] != sp[i][b]) re += dist[i][a] + dist[i][b], a = sp[i][a], b = sp[i][b];
	return re+dist[0][a]+dist[0][b];
}
int lca3(int a,int b,int c,int k){
	if(lev[a]-lev[c] >= k){
		for(int i=17;i>=0;i--) if(k&(1<<i)) a = sp[i][a];
		return a;
	}
	k -= lev[a]-lev[c];
	k = lev[b]-lev[c]-k;
	for(int i=17;i>=0;i--) if(k&(1<<i)) b = sp[i][b];
	return b;
}
int lca2(int a,int b,int k){
	int A=a,B=b;
	if(lev[a] < lev[b]) swap(a,b);
	for(int i=17;i>=0;i--) if((lev[a]-lev[b])&(1<<i)) a = sp[i][a];
	if(a == b) return lca3(A,B,a,k);
	for(int i=17;i>=0;i--) if(sp[i][a] != sp[i][b]) a = sp[i][a], b = sp[i][b];
	return lca3(A,B,sp[0][a],k);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c});
    	v[b].push_back({a,c});
    }
    dfs(1,0,0);
    for(int i=1;i<=17;i++) for(int j=1;j<=n;j++) sp[i][j] = sp[i-1][sp[i-1][j]], dist[i][j] = dist[i-1][sp[i-1][j]] + dist[i-1][j];
    scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b,c,d; scanf("%d",&a);
		if(a == 1){
			scanf("%d %d",&b,&c);
			printf("%lld\n",lca1(b,c));
		}else{
			scanf("%d %d %d",&b,&c,&d);
			printf("%d\n",lca2(b,c,--d));
		}
	}
}
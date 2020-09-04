// boj.kr/11438
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 101010
#define log (int)log2(MAX_N)+1

int n,m,sp[log+1][MAX_N],lev[MAX_N];
vector<int> v[MAX_N];

void dfs(int cur,int par){
	lev[cur] = lev[par]+1;
	sp[0][cur] = par;
	for(int nxt : v[cur]) if(nxt != par) dfs(nxt, cur);
}

int lca(int a, int b){
    if(lev[a] < lev[b]) swap(a, b);
    for(int i=0;i<=log;i++) if((1 << i) & (lev[a] - lev[b])) a = sp[i][a];
    for(int i=log;i>=0;i--) if(sp[i][a] != sp[i][b]) a = sp[i][a], b = sp[i][b];
    return a == b ? a : sp[0][a];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=log;i++) for(int j=1;j<=n;j++) sp[i][j] = sp[i-1][sp[i-1][j]];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
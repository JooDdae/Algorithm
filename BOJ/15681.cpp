#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q, sz[100100];
vector<int> v[100100];
int dfs(int cur, int par){
	sz[cur] = 1;
	for(int nxt : v[cur]) if(nxt != par) sz[cur] += dfs(nxt, cur);
	return sz[cur];
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(m, -1);
	while(q--){
		int a; scanf("%d",&a);
		printf("%d\n",sz[a]);
	}
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, ans[100100], p[100100];
vector<int> v[100100];
void dfs(int u, int val){
	ans[u] = val;
	for(auto x : v[u]) dfs(x, val + p[x]);
}
int main(){
	scanf("%d %d %*d",&n,&m);
	for(int i=2;i<=n;i++){
		int a; scanf("%d",&a);
		v[a].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int a, b; scanf("%d %d",&a,&b);
		p[a] += b;
	}
	dfs(1, p[1]);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
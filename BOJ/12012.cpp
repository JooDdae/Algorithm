#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, ans[200200], par[200200], sz[200200], chk[200200], q[200200];
vector<int> v[200200];
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
void merge(int a, int b){
	a = f(a), b = f(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	par[b] = a;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) par[i] = i, sz[i] = 1;
	for(int i=1;i<=m;i++){
		int a, b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++) scanf("%d",q+i);
	for(int i=n;i>=1;i--){
		chk[q[i]] = 1;
		for(int x : v[q[i]]) if(chk[x]) merge(q[i], x);
		ans[i] = (sz[f(q[i])] == n-i+1);
	}
	for(int i=1;i<=n;i++) puts(ans[i] ? "YES" : "NO");
}
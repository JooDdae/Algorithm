#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, in[100100], out[100100], tree[100100], cnt;
vector<int> v[100100];
void update(int bit, int val){
	while(bit <= n){
		tree[bit] += val;
		bit += bit & -bit;
	}
}
int find(int bit){
	int re = 0;
	while(bit){
		re += tree[bit];
		bit -= bit & -bit;
	}
	return re;
}
void dfs(int u){
	in[u] = ++cnt;
	for(auto x : v[u]) dfs(x);
	out[u] = cnt;
}
int main(){
	scanf("%d %d %*d",&n,&m);
	for(int i=2;i<=n;i++){
		int a; scanf("%d",&a);
		v[a].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		int a, b, c; scanf("%d",&a);
		if(a == 1){
			scanf("%d %d",&b,&c);
			update(in[b], c);
			update(out[b]+1, -c);
		}else{
			scanf("%d",&b);
			printf("%d\n",find(in[b]));
		}
	}
}
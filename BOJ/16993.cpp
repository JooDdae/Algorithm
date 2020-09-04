#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
struct Node{
	int l, r, mx, sum;
}tree[400400];
int n, m, a[100100], INF = 1e9;
Node build(int node, int l, int r){
	if(l == r) return tree[node] = {a[l], a[l], a[l], a[l]};
	Node L = build(node*2, l, mid), R = build(node*2+1, mid+1, r);
	return tree[node] = {max(L.l, L.sum+R.l), max(R.r, L.r+R.sum), max({L.mx, R.mx, L.r + R.l, L.sum + R.sum}), L.sum + R.sum};
}
Node query(int node, int l, int r, int nl, int nr){
	if(r<nl || nr<l) return {-INF, -INF, -INF, 0};
	if(nl <= l && r <= nr) return tree[node];
	Node L = query(node*2, l, mid, nl, nr), R = query(node*2+1, mid+1, r, nl, nr);
	return {max(L.l, L.sum+R.l), max(R.r, L.r+R.sum), max({L.mx, R.mx, L.r + R.l, L.sum + R.sum}), L.sum + R.sum};
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	build(1, 1, n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		printf("%d\n",query(1, 1, n, a, b).mx);
	}
}
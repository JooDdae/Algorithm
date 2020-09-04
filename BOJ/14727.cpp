#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n, a[100100];
pair<int, int> tree[400400];
void up(int node, int l, int r, int id, int val){
	if(id < l || r < id) return;
	if(l == r){
		tree[node] = {val, id};
		return;
	}
	up(node*2, l, mid, id, val);
	up(node*2+1, mid+1, r, id, val);
	tree[node] = min(tree[node*2], tree[node*2+1]);
}
pair<int,int> find(int node, int l, int r, int nl, int nr){
	if(r<nl || nr<l) return {1000001, 0};
	if(nl<=l && r<=nr) return tree[node];
	return min(find(node*2, l, mid, nl, nr), find(node*2+1, mid+1, r, nl, nr));
}
ll f(int l, int r){
	if(l == r) return a[l];
	pair<int,int> p = find(1, 1, n, l, r);
	return max({1ll * p.first * (r - l + 1), l < p.second ? f(l, p.second-1) : 0, p.second < r ? f(p.second+1, r) : 0});
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		up(1, 1, n, i, a[i]);
	}
	printf("%lld",f(1, n));
}
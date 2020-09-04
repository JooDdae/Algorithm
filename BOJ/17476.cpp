#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct node{
	ll mx, mn, sum;
}tree[400400];
int n, m;
ll ar[100100], lazy1[400400], lazy2[400400];

node merge(node a, node b){
	return {max(a.mx, b.mx), min(a.mn, b.mn), a.sum + b.sum};
}

node &build(int node, int l, int r){
	if(l == r) return tree[node] = {ar[l], ar[l], ar[l]};
	return tree[node] = merge(build(node*2, l, mid), build(node*2+1, mid+1, r));
}

void lazy_update(int node, int l, int r){
	if(!lazy1[node] && !lazy2[node]) return;

	if(!lazy2[node]){
		tree[node].mx += lazy1[node];
		tree[node].mn += lazy1[node];
		tree[node].sum += (r - l + 1) * lazy1[node];
		if(l != r){
			lazy1[node*2] += lazy1[node];
			lazy1[node*2+1] += lazy1[node];
		}
	}
	else{
		tree[node].mx = tree[node].mn = lazy1[node] + lazy2[node];
		tree[node].sum = (r - l + 1) * tree[node].mn;
		if(l != r){
			lazy1[node*2] = lazy1[node*2+1] = 0;
			lazy2[node*2] = lazy2[node*2+1] = lazy1[node] + lazy2[node];
		}
	}
	lazy1[node] = lazy2[node] = 0;
}

void range_sum(int node, int l, int r, int nl, int nr, int x){
	lazy_update(node, l, r);
	if(nr < l || r < nl) return;
	if(nl <= l && r <= nr){
		lazy1[node] += x;
		lazy_update(node, l, r);
		return;
	}
	range_sum(node*2, l, mid, nl, nr, x);
	range_sum(node*2+1, mid+1, r, nl, nr, x);
	tree[node] = merge(tree[node*2], tree[node*2+1]);
}

void range_sqrt(int node, int l, int r, int nl, int nr){
	lazy_update(node, l, r);
	if(nr < l || r < nl) return;
	if(nl <= l && r <= nr){
		if(floor(sqrt(tree[node].mn)) == floor(sqrt(tree[node].mx))){
			lazy2[node] = floor(sqrt(tree[node].mx));
			lazy_update(node, l, r);
			return;
		}
		if(tree[node].mx == tree[node].mn + 1){
			lazy1[node] = floor(sqrt(tree[node].mx)) - tree[node].mx;
			lazy_update(node, l, r);
			return;
		}
	}
	range_sqrt(node*2, l, mid, nl, nr);
	range_sqrt(node*2+1, mid+1, r, nl, nr);
	tree[node] = merge(tree[node*2], tree[node*2+1]);
}

ll find(int node, int l, int r, int nl, int nr){
	lazy_update(node, l, r);
	if(nr < l || r < nl) return 0;
	if(nl <= l && r <= nr) return tree[node].sum;
	return find(node*2, l, mid, nl, nr) + find(node*2+1, mid+1, r, nl, nr);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",ar+i);
	build(1, 1, n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a, b, c, d; scanf("%d",&a);
		if(a == 1){
			scanf("%d %d %d",&b,&c,&d);
			range_sum(1, 1, n, b, c, d);
		}
		if(a == 2){
			scanf("%d %d",&b,&c);
			range_sqrt(1, 1, n, b, c);
		}
		if(a == 3){
			scanf("%d %d",&b,&c);
			printf("%lld\n",find(1, 1, n, b, c));
		}
	}
}
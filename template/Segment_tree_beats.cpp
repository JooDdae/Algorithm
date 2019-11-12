//boj.kr/17474 min update, max&sum query
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mid ((l+r)>>1)
#define MAX_N 1001001

struct Node{
	int mx1,mx2,cnt_mx;
	ll sum;
}tree[4*MAX_N];
int n,q,a[MAX_N];

Node mer(Node a, Node b){
	if(a.mx1 == b.mx1) return {a.mx1, a.mx1, a.cnt_mx+b.cnt_mx, a.sum+b.sum};
	if(a.mx1 > b.mx1) swap(a,b);
	return {b.mx1, max(a.mx1, b.mx2), b.cnt_mx, a.sum+b.sum};
}

Node build(int node,int l,int r){
	if(l == r) return tree[node] = {a[l], -1, 1, a[l]};
	return tree[node] = mer(build(node*2,l,mid), build(node*2+1,mid+1,r));
}

void lazy_up(int node,int l,int r){
	if(l != r){
		for(auto i : {node*2, node*2+1}){
			if(tree[node].mx1 < tree[i].mx1){
				tree[i].sum -= 1ll * tree[i].cnt_mx * (tree[i].mx1 - tree[node].mx1);
				tree[i].mx1 = tree[node].mx1;
			}
		}
	}
}

void update_min(int node,int l,int r,int nl,int nr,int v){
	lazy_up(node,l,r);
	if(r<nl || nr<l || tree[node].mx1 <= v) return;
	if(nl<=l && r<=nr && tree[node].mx2 < v){
		tree[node].sum -= 1ll * tree[node].cnt_mx * (tree[node].mx1 - v);
		tree[node].mx1 = v;
		lazy_up(node,l,r);
		return;
	}
	update_min(node*2,l,mid,nl,nr,v);
	update_min(node*2+1,mid+1,r,nl,nr,v);
	tree[node] = mer(tree[node*2], tree[node*2+1]);
}

ll find_max(int node,int l,int r,int nl,int nr){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node].mx1;
	return max(find_max(node*2,l,mid,nl,nr), find_max(node*2+1,mid+1,r,nl,nr));
}

ll find_sum(int node,int l,int r,int nl,int nr){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node].sum;
	return find_sum(node*2,l,mid,nl,nr) + find_sum(node*2+1,mid+1,r,nl,nr);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&q);
	while(q--){
		int t,l,r,x; scanf("%d %d %d",&t,&l,&r);
		if(t == 1){
			scanf("%d",&x);
			update_min(1,1,n,l,r,x);
		}else printf("%lld\n",(t==2?find_max:find_sum)(1,1,n,l,r));
	}
}
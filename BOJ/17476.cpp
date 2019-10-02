#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct node{
	ll mx,sum;
}tree[400040];
int n,a[100010],m;
ll lazy[400040];
bool eq[400040];
node mer(node a,node b){
	return {max(a.mx, b.mx), a.sum + b.sum};
}
node build(int node,int l,int r){
	if(l == r) return tree[node] = {a[l], a[l]};
	return tree[node] = mer(build(node*2,l,mid), build(node*2+1,mid+1,r));
}
void lazy_up(int node,int l,int r){
	if(lazy[node]){
		tree[node].sum += lazy[node] * (r-l+1);
		tree[node].mx += lazy[node];
		if(l != r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(eq[node]){
		if(l!=r){
			ll x = tree[node].mx;
			tree[node*2].mx = tree[node*2+1].mx = x;
			tree[node*2].sum = x*(mid-l+1);
			tree[node*2+1].sum = x*(r-mid);
			eq[node*2] = eq[node*2+1] = 1;
			lazy[node*2] = lazy[node*2+1] = 0;
		}
		eq[node] = 0;
	}
}
void range_sum(int node,int l,int r,int nl,int nr,int x){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		lazy[node] += x;
	lazy_up(node,l,r);
		return;
	}
	range_sum(node*2,l,mid,nl,nr,x);
	range_sum(node*2+1,mid+1,r,nl,nr,x);
	tree[node] = mer(tree[node*2], tree[node*2+1]);
}
void range_sqrt(int node,int l,int r,int nl,int nr){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr && tree[node].mx*(r-l+1) == tree[node].sum){
		ll x = sqrt(tree[node].mx) + 1e-8;
		tree[node].mx = x;
		tree[node].sum = x*(r-l+1);
		eq[node] = 1;
		return;
	}
	range_sqrt(node*2,l,mid,nl,nr);
	range_sqrt(node*2+1,mid+1,r,nl,nr);
	tree[node] = mer(tree[node*2], tree[node*2+1]);
}
ll find(int node,int l,int r,int nl,int nr){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node].sum;
	return find(node*2,l,mid,nl,nr) + find(node*2+1,mid+1,r,nl,nr);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		int a,l,r,x; scanf("%d",&a);
		if(a == 1){
			scanf("%d %d %d",&l,&r,&x);
			range_sum(1,1,n,l,r,x);
		}else if(a == 2){
			scanf("%d %d",&l,&r);
			range_sqrt(1,1,n,l,r);
		}else if(a == 3){
			scanf("%d %d",&l,&r);
			printf("%lld\n",find(1,1,n,l,r));
		}
	}
}
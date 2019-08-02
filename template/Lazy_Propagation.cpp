// boj.kr/10999
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 1010101
#define mid ((l+r)>>1)

int n,m,k;
ll tree[MAX_N*4], lazy[MAX_N*4];

void lazy_update(int node,int l,int r){
	if(lazy[node]){
		tree[node] += lazy[node]*(r-l+1);
		if(l!=r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node,int l,int r,int nl,int nr,int val){
	lazy_update(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		lazy[node] += val;
		lazy_update(node,l,r);
		return;
	}
	update(node*2,l,mid,nl,nr,val);
	update(node*2+1,mid+1,r,nl,nr,val);
	tree[node] = tree[node*2] + tree[node*2+1];
}
ll find(int node,int l,int r,int nl,int nr){
	lazy_update(node,l,r);
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return find(node*2,l,mid,nl,nr) + find(node*2+1,mid+1,r,nl,nr);
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		update(1,1,n,i,i,a);
	}
	for(int i=1;i<=m+k;i++){
		int a,b,c,d; scanf("%d",&a);
		if(a == 1){
			scanf("%d %d %d",&b,&c,&d);
			update(1,1,n,b,c,d);
		}else{
			scanf("%d %d",&b,&c);
			printf("%lld\n",find(1,1,n,b,c));
		}
	}
}
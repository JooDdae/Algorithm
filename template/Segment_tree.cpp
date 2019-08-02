// boj.kr/2042
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 1010101
#define mid ((l+r)>>1)

int n,m,k;
ll tree[MAX_N*4];

void update(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] = val;
		return;
	}
	update(node*2,l,mid,id,val);
	update(node*2+1,mid+1,r,id,val);
	tree[node] = tree[node*2]+tree[node*2+1];
}

ll find(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return find(node*2,l,mid,nl,nr)+find(node*2+1,mid+1,r,nl,nr);
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		update(1,1,n,i,a);
	}
	for(int i=1;i<=m+k;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		if(a == 1) update(1,1,n,b,c);
		else printf("%lld\n",find(1,1,n,b,c));
	}
}
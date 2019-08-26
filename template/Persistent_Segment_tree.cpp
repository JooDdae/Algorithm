//boj.kr/16978
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 101010
#define mid ((l+r)>>1)

struct node{
	int l,r;
	ll val;
}tree[20*MAX_N];
int n,m,root[MAX_N],rc,cnt;

void build(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node].val = val;
		return;
	}
	if(!tree[node].l) tree[node].l = ++cnt;
	if(!tree[node].r) tree[node].r = ++cnt;
	build(tree[node].l,l,mid,id,val);
	build(tree[node].r,mid+1,r,id,val);
	tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
}

void up(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node].val = val;
		return;
	}

	if(id <= mid){
		tree[++cnt] = tree[tree[node].l];
		tree[node].l = cnt;
		up(cnt,l,mid,id,val);
	}else{
		tree[++cnt] = tree[tree[node].r];
		tree[node].r = cnt;
		up(cnt,mid+1,r,id,val);
	}
	tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
}

ll f(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node].val;
	return f(tree[node].l,l,mid,nl,nr) + f(tree[node].r,mid+1,r,nl,nr);
}

int main(){
    scanf("%d",&n);
    root[0] = ++cnt;
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	build(1,1,n,i,a);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int a,b,c,d; scanf("%d",&a);
    	if(a == 1){
    		scanf("%d %d",&b,&c);
    		root[++rc] = ++cnt;
    		tree[cnt] = tree[root[rc-1]];
    		up(cnt,1,n,b,c);
    	}else{
    		scanf("%d %d %d",&b,&c,&d);
    		printf("%lld\n",f(root[b],1,n,c,d));
    	}
    }
}
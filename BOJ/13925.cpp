#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
ll mod=1e9 + 7,tree[404040],lazy[404040][2];
int n,q;
void lazy_update(int node,int l,int r){
	if(l!=r){
		(lazy[node*2][0] *= lazy[node][0]) %= mod;
		lazy[node*2][1] = (lazy[node*2][1] * lazy[node][0] + lazy[node][1]) % mod;

		(lazy[node*2+1][0] *= lazy[node][0]) %= mod;
		lazy[node*2+1][1] = (lazy[node*2+1][1] * lazy[node][0] + lazy[node][1]) % mod;
	}
	tree[node] = (tree[node] * lazy[node][0] + lazy[node][1] * (r-l+1)) % mod;
	lazy[node][0] = 1, lazy[node][1] = 0;
}
void up(int node,int l,int r,int nl,int nr,int p,int g){
	lazy_update(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		(lazy[node][0]*=g)%=mod;
		lazy[node][1]=(lazy[node][1]*g+p)%mod;
		lazy_update(node,l,r);
		return;
	}
	up(node*2,l,mid,nl,nr,p,g);
	up(node*2+1,mid+1,r,nl,nr,p,g);
	tree[node] = (tree[node*2] + tree[node*2+1]) % mod;
}
ll f(int node,int l,int r,int nl,int nr){
	lazy_update(node,l,r);
	if(r<nl || nr<l) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return (f(node*2,l,mid,nl,nr) + f(node*2+1,mid+1,r,nl,nr))%mod;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	up(1,1,n,i,i,a,1);
    }
    scanf("%d",&q);
    while(q--){
    	int a,b,c; scanf("%d",&a);
    	if(a == 1){
    		scanf("%d %d %d",&a,&b,&c);
    		up(1,1,n,a,b,c,1);
    	}else if(a == 2){
    		scanf("%d %d %d",&a,&b,&c);
    		up(1,1,n,a,b,0,c);
    	}else if(a == 3){
    		scanf("%d %d %d",&a,&b,&c);
    		up(1,1,n,a,b,0,0);
    		up(1,1,n,a,b,c,1);
    	}else if(a == 4){
    		scanf("%d %d",&a,&b);
    		printf("%lld\n",f(1,1,n,a,b));
    	}
    }
}
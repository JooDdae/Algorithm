#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n,q,m[505050],in[505050],out[505050],cnt;
vector<int> v[505050];
ll lazy[2020202],tree[2020202];
void dfs(int cur,int par){
	in[cur] = ++cnt;
	for(int nxt : v[cur]) if(nxt != par) dfs(nxt, cur);
	out[cur] = cnt;
}
void lazy_up(int node,int l,int r){
	if(l != r){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}else tree[node] += lazy[node];
	lazy[node]=0;
}
void up(int node,int l,int r,int nl,int nr,int val){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		lazy[node] += val;
		return;
	}
	up(node*2,l,mid,nl,nr,val);
	up(node*2+1,mid+1,r,nl,nr,val);
}
ll f(int node,int l,int r,int id){
	lazy_up(node,l,r);
	if(id<l || r<id) return 0;
	if(l == r) return tree[node];
	return f(node*2,l,mid,id) + f(node*2+1,mid+1,r,id);
}
int main(){
    scanf("%d %d %d",&n,&q,&m[1]);
    for(int i=2;i<=n;i++){
    	int a; scanf("%d %d",&m[i],&a);
    	v[a].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) up(1,1,n,in[i],in[i],m[i]);
    while(q--){
    	char a; scanf(" %c",&a);
    	if(a == 'p'){
    		int b,c; scanf("%d %d",&b,&c);
    		if(in[b]!=out[b]) up(1,1,n,in[b]+1,out[b],c);
    	}else{
    		int b; scanf("%d",&b);
    		printf("%lld\n",f(1,1,n,in[b]));
    	}
    }
}
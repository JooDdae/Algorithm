#include<bits/stdc++.h>
using namespace std;
#define MAX_N 500050
#define int unsigned
#define mid ((l+r)>>1)
int n,q,cnt=1,lev[MAX_N],head[MAX_N],p[MAX_N],in[MAX_N],out[MAX_N],sz[MAX_N],tree[MAX_N*4],ls[MAX_N*4],lg[MAX_N*4];
vector<int> v[MAX_N];

void lazy_up(int node,int l,int r){
	if(ls[node]==0 && lg[node]==1) return;
	if(l!=r){
		lg[node*2] *= lg[node];
		ls[node*2] = lg[node]*ls[node*2] + ls[node];
		lg[node*2+1] *= lg[node];
		ls[node*2+1] = lg[node]*ls[node*2+1] + ls[node];
	}
	tree[node] = lg[node]*tree[node] + ls[node]*(r-l+1);
	lg[node]=1, ls[node]=0;
}

void up(int node,int l,int r,int nl,int nr,int pl,int g){
	lazy_up(node,l,r);
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		lg[node] *= g;
		ls[node] *= g;
		ls[node] += pl;
		lazy_up(node,l,r);
		return;
	}
	up(node*2,l,mid,nl,nr,pl,g);
	up(node*2+1,mid+1,r,nl,nr,pl,g);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int f(int node,int l,int r,int nl,int nr){
	lazy_up(node,l,r);
	if(r<nl || nr<l || l>r) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return f(node*2,l,mid,nl,nr) + f(node*2+1,mid+1,r,nl,nr);
}

int dfs_size(int cur){
	sz[cur] = 1;
	lev[cur] = lev[p[cur]]+1;
	for(int &nxt : v[cur]){
		if(nxt == p[cur]) continue;
		p[nxt] = cur;
		sz[cur] += dfs_size(nxt);
		if(sz[nxt] > sz[v[cur][0]]) swap(nxt, v[cur][0]);
	}
	return sz[cur];
}

void dfs_hld(int cur){
	in[cur] = cnt;
	for(int nxt : v[cur]){
		if(nxt == p[cur]) continue;
		head[nxt] = nxt == v[cur][0] ? head[cur] : nxt;
		++cnt;
		dfs_hld(nxt);
	}
	out[cur] = cnt;
}

void up_hld(int a,int b,int pl,int g){
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		up(1,1,n,in[head[a]],in[a],pl,g);
		a = p[head[a]];
	}
	if(in[a] > in[b]) swap(a,b);
	up(1,1,n,in[a],in[b],pl,g);
}

int hld(int a,int b){
	int re=0;
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		re += f(1,1,n,in[head[a]],in[a]);
		a = p[head[a]];
	}
	if(in[a] > in[b]) swap(a,b);
	return re + f(1,1,n,in[a],in[b]);
}

signed main(){
    scanf("%u %u",&n,&q);
    for(int i=1;i<n;i++){
    	int a,b; scanf("%u %u",&a,&b);
    	v[a].push_back(b);
    	v[b].push_back(a);
    }
    for(int i=1;i<=4*n;i++) lg[i] = 1;
    dfs_size(1);
    dfs_hld(1);
    while(q--){
    	int a,b,c; scanf("%u",&a);
    	if(a == 1){
    		scanf("%u %u",&a,&b);
    		up(1,1,n,in[a],out[a],b,1);
    	}
    	else if(a == 2){
    		scanf("%u %u %u",&a,&b,&c);
    		up_hld(a,b,c,1);
    	}
    	else if(a == 3){
    		scanf("%u %u",&a,&b);
    		up(1,1,n,in[a],out[a],0,b);
    	}
    	else if(a == 4){
    		scanf("%u %u %u",&a,&b,&c);
    		up_hld(a,b,0,c);
    	}
    	else if(a == 5){
    		scanf("%u",&a);
    		printf("%u\n",f(1,1,n,in[a],out[a]));
    	}
    	else if(a == 6){
    		scanf("%u %u",&a,&b);
    		printf("%u\n",hld(a,b));
    	}
    }
}
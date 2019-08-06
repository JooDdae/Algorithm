// boj.kr/13510
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 101010
#define mid ((l+r)>>1)

struct node{
	int to,cost,id;
};
int n,q,tree[MAX_N*4],size[MAX_N],t[MAX_N],head[MAX_N],lev[MAX_N],before[MAX_N],in[MAX_N],p[MAX_N],cnt;
vector<node> v[MAX_N];

void update(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] = val;
		return;
	}
	update(node*2,l,mid,id,val);
	update(node*2+1,mid+1,r,id,val);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}

int find(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l || l>r) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return max(find(node*2,l,mid,nl,nr), find(node*2+1,mid+1,r,nl,nr));
}

void dfs_size(int cur,int par){
	size[cur] = 1;
	lev[cur] = lev[par]+1;
	for(node &nxt : v[cur]){
		if(nxt.to == par) continue;
		dfs_size(nxt.to, cur);
		size[cur] += size[nxt.to];
		if(size[nxt.to] > size[v[cur][0].to]) swap(nxt, v[cur][0]);
	}
}

void dfs_hld(int cur,int par){
	in[cur] = cnt;
	for(node &nxt : v[cur]){
		if(nxt.to == par) continue;
		head[nxt.to] = nxt.to==v[cur][0].to ? head[cur]:nxt.to;
		p[nxt.to] = cur;
		update(1,1,n,++cnt,nxt.cost);
		before[nxt.id] = cnt;
		dfs_hld(nxt.to, cur);
	}
}

int hld(int a,int b){
	int re=0;
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		re = max(re, find(1,1,n,in[head[a]],in[a]));
		a = p[head[a]];
	}
	if(in[a] > in[b]) swap(a,b);
	return max(re, find(1,1,n,in[a]+1,in[b]));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c,i});
    	v[b].push_back({a,c,i});
    }
    dfs_size(1,0);
    dfs_hld(1,0);
    scanf("%d",&q);
    while(q--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	if(a == 1) update(1,1,n,before[b],c);
    	else printf("%d\n",hld(b,c));
    }
}
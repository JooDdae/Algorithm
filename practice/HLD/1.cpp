// boj.kr/13510 트리와 쿼리 1 / 구현 실패
#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cost,id;
};
int n,m,cnt,tree[404040],lev[101010],size[101010],in[101010],bf[101010],p[101010],head[101010];
vector<node> v[101010];
void up(int node,int l,int r,int id,int val){
	if(id<l || r<id) return;
	if(l == r){
		tree[node] = val;
		return;
	}
	up(node*2,l,(l+r)/2,id,val);
	up(node*2+1,(l+r)/2+1,r,id,val);
	tree[node] = max(tree[node*2], tree[node*2+1]);
}
int f(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l || nl>nr) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return max(f(node*2,l,(l+r)/2,nl,nr),f(node*2+1,(l+r)/2+1,r,nl,nr));
}
int dfs_size(int cur,int par){
	size[cur] = 1;
	lev[cur] = lev[p[cur]]+1;
	for(auto &nxt : v[cur]){
		if(nxt.to == par) continue;
		p[nxt.to]= cur;
		size[cur] += dfs_size(nxt.to, cur);
		if(size[nxt.to] > size[v[cur][0].to]) swap(nxt, v[cur][0]);
	}
	return size[cur];
}
void dfs_hld(int cur,int par){
	in[cur] = cnt;
	for(auto nxt : v[cur]){
		if(nxt.to == par) continue;
		head[nxt.to] = nxt.to == v[cur][0].to ? head[cur] : nxt.to;
		up(1,1,n,++cnt,nxt.cost);
		bf[nxt.id] = cnt;
		dfs_hld(nxt.to, cur);
	}
}
int hld(int a,int b){
	int re=0;
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		re = max(re, f(1,1,n,in[head[a]],in[a]));
		a = p[head[a]];
	}
	if(in[a] > in[b]) swap(a,b);
	return max(re, f(1,1,n,in[a]+1,in[b]));
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
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	if(a == 1) up(1,1,n,bf[b],c);
    	else printf("%d\n",hld(b,c));
    }
}
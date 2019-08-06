#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
int n,m,sz[101010],lev[101010],p[101010],in[101010],head[101010],cnt;
pair<int,int> tree[404040];
vector<pair<int,int>> v[101010];
void up(int node,int l,int r,int id,int val){
	if(id < l || r < id) return;
	if(l == r){
		tree[node] = {val,val};
		return;
	}
	up(node*2,l,mid,id,val);
	up(node*2+1,mid+1,r,id,val);
	tree[node] = {min(tree[node*2].first,tree[node*2+1].first),max(tree[node*2].second,tree[node*2+1].second)};
}
pair<int,int> find(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l || l>r) return {1e9,0};
	if(nl<=l && r<=nr) return tree[node];
	pair<int,int> f1=find(node*2,l,mid,nl,nr),f2=find(node*2+1,mid+1,r,nl,nr);
	return {min(f1.first,f2.first),max(f1.second,f2.second)};
}
void dfs_size(int cur,int par){
	sz[cur] = 1;
	lev[cur] = lev[par]+1;
	p[cur] = par;
	for(pair<int,int> &nxt : v[cur]){
		if(nxt.first == par) continue;
		dfs_size(nxt.first, cur);
		sz[cur] += sz[nxt.first]; 
		if(sz[v[cur][0].first] < sz[nxt.first]) swap(nxt, v[cur][0]);
	}
}
void dfs_hld(int cur,int par){
	in[cur] = cnt;
	for(pair<int,int> &nxt : v[cur]){
		if(nxt.first == par) continue;
		head[nxt.first] = nxt.first == v[cur][0].first ? head[cur] : nxt.first;
		up(1,1,n,++cnt,nxt.second);
		dfs_hld(nxt.first, cur);
	}
}
pair<int,int> hld(int a,int b){
	pair<int,int> re = {1e9,0};
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		pair<int,int> fl = find(1,1,n,in[head[a]],in[a]);
		re = {min(re.first, fl.first), max(re.second, fl.second)};
		a = p[head[a]];
	}
	if(in[a] > in[b]) swap(a,b);
	pair<int,int> fl = find(1,1,n,in[a]+1,in[b]);
	return {min(re.first, fl.first), max(re.second, fl.second)};
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c});
    	v[b].push_back({a,c});
    }
    dfs_size(1,0);
    dfs_hld(1,0);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	pair<int,int> fl = hld(a,b);
    	printf("%d %d\n",fl.first,fl.second);
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,q,sz[202020],p[202020],head[202020],in[202020],lev[202020],tree[808080],cnt;
vector<int> v[202020];
void up(int node,int l,int r,int id){
	if(id<l || r<id || !id) return;
	if(l == r){
		tree[node] = 1;
		return;
	}
	up(node*2,l,(l+r)/2,id);
	up(node*2+1,(l+r)/2+1,r,id);
	tree[node] = tree[node*2] | tree[node*2+1];
}
int f(int node,int l,int r,int nl,int nr){
	if(r<nl || nr<l || nl>nr) return 0;
	if(nl<=l && r<=nr) return tree[node];
	return f(node*2,l,(l+r)/2,nl,nr) | f(node*2+1,(l+r)/2+1,r,nl,nr);
}
int dfs_size(int cur){
	lev[cur] = lev[p[cur]]+1;
	for(auto &nxt : v[cur]){
		sz[cur] += dfs_size(nxt);
		if(sz[nxt] > sz[v[cur][0]]) swap(nxt, v[cur][0]);
	}
	return sz[cur];
}
void dfs_hld(int cur){
	in[cur] = cnt++;
	for(auto &nxt : v[cur]){
		head[nxt] = nxt == v[cur][0] ? head[cur] : nxt;
		dfs_hld(nxt);
	}
}
int hld(int a,int b){
	int re=0;
	while(head[a] != head[b]){
		if(lev[head[a]] < lev[head[b]]) swap(a,b);
		re |= f(1,1,n,in[head[a]],in[a]);
		a = p[head[a]];
	}
	if(lev[a] > lev[b]) swap(a,b);
	return re | f(1,1,n,in[a]+1,in[b]);
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++) scanf("%d",&p[i]);
    for(int i=2;i<=n;i++) v[p[i]].push_back(i);
    dfs_size(1);
	dfs_hld(1);
    while(q--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	int fl = hld(a,b);
    	printf("%s\n",fl?"NO":"YES");
    	if(c){
    		if(fl) up(1,1,n,in[b]);
    		else up(1,1,n,in[a]);
    	}
    }
}
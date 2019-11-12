#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
int n,m,mx=1,cnt,par[101010],sz[101010],tree2[404040];
pair<int,int> p[101010],q[101010];
vector<int> v[101010],tree[404040];
map<pair<int,int>, int> mp;
void up(int node,int l,int r,int nl,int nr,int x){
	if(r<nl || nr<l) return;
	if(nl<=l && r<=nr){
		tree[node].push_back(x);
		return;
	}
	up(node*2,l,mid,nl,nr,x);
	up(node*2+1,mid+1,r,nl,nr,x);
}

void up2(int node,int l,int r,int x){
	if(x<l || r<x) return;
	if(l == r){
		tree2[node] = 1;
		return;
	}
	up2(node*2,l,mid,x);
	up2(node*2+1,mid+1,r,x);
	tree2[node] = tree2[node*2] + tree2[node*2+1];
}

int f(int a){
	if(a == par[a]) return a;
	return f(par[a]);
}

void uni(int a,int b){
	par[a] = b;
	sz[b] += sz[a];
}

void rm(int a,int b){
	par[a] = a;
	sz[b] -= sz[a];
}

void dfs(int node,int l,int r){
	if(l == r){
		cout << (f(q[l].first) == f(q[l].second)) << '\n';
		return;
	}

	stack<pair<int,int>> st;
	for(int nxt : tree[node]){
		pair<int,int> c = p[nxt];
		c.first = f(c.first);
		c.second = f(c.second);
		if(sz[c.first] > sz[c.second]) swap(c.first, c.second);
		uni(c.first, c.second);
		st.push(c);
	}

	if(tree2[node*2]) dfs(node*2,l,mid);
	if(tree2[node*2+1]) dfs(node*2+1,mid+1,r);

	while(!st.empty()){
		rm(st.top().first, st.top().second);
		st.pop();
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	
	while(mx < m) mx *= 2;

	for(int i=1;i<=n;i++) par[i] = i, sz[i] = 1;
	for(int i=1;i<=m;i++){
		int a,b,c; cin >> a >> b >> c;
		if(b > c) swap(b,c);
		if(a == 3){
			q[i] = {b,c};
			up2(1,1,mx,i);
		}else{
			if(!mp[{b,c}]){
				mp[{b,c}] = ++cnt;
				p[cnt] = {b,c};
			}
			v[mp[{b,c}]].push_back(i);
		}
	}

	for(int i=1;i<=cnt;i++){
		for(int j=0;j<v[i].size();j+=2){
			if(j == v[i].size()-1) up(1,1,mx,v[i][j],mx,i);
			else up(1,1,mx,v[i][j],v[i][j+1],i);
		}
	}

	dfs(1,1,mx);
}
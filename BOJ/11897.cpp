#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k, x[200200], y[200200], p[777], sz[777];
vector<int> l, r;

int f(int a){
	if(a == p[a]) return a;
	return p[a] = f(p[a]);
}

int merge(int a, int b){
	a = f(a), b = f(b);
	if(a == b) return 0;
	if(sz[a] > sz[b]) swap(a, b);
	p[a] = b;
	sz[b] += sz[a];
	return 1;
}

int find(int a, int b){
	int re = n;
	for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
	for(auto i : l){
		if(i > a) break;
		re -= merge(x[i], y[i]);
	}
	for(auto i : r){
		if(i < b) break;
		re -= merge(x[i], y[i]);
	}
	return re;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d %d",x+i,y+i);

	for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
	for(int i=1;i<=m;i++) if(merge(x[i], y[i])) l.push_back(i);
	for(int i=1;i<=n;i++) p[i] = i, sz[i] = 1;
	for(int i=m;i>=1;i--) if(merge(x[i], y[i])) r.push_back(i);

	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int a, b; scanf("%d %d",&a,&b);
		printf("%d\n",find(a-1, b+1));
	}
}
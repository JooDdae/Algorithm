#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int to,cap,val,r;
	char d;
};
vector<node> v[10010];
int n, a[2525], b[2525], chk[10010], cnt, source, sink, ans;
ll A[10010];
map<ll,int> mp;

void addEdge(int l,int r,int cap,char d='.'){
	v[l].push_back({r, cap, 0, v[r].size(),d});
	v[r].push_back({l, 0, 0, v[l].size()-1,d});
}

void add(int u, ll c, char h){
	if(!mp[c]){
		mp[c] = ++cnt;
		A[cnt] = c;
		addEdge(sink + cnt, sink, 1, h);
	}
	addEdge(u, sink + mp[c], 1, h);
}

int f(int cur,int cap){
	if(cur == sink) return cap;
	chk[cur] = 1;
	for(node &e : v[cur]){
		if(chk[e.to] || e.val == e.cap) continue;
		int fl = f(e.to, min(cap, e.cap-e.val));
		if(fl){
			e.val += fl;
			v[e.to][e.r].val -= fl;
			return fl;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	source = n+1, sink = n+2;

	for(int i=1;i<=n;i++){
		scanf("%d %d",a+i,b+i);
		add(i, a[i] + b[i], '+');
		add(i, a[i] - b[i], '-');
		add(i, 1ll * a[i] * b[i], '*');
		addEdge(source, i, 1);
	}

	while(1){
		int fl = f(source ,1e9);
		if(!fl) break;
		ans += fl;
		for(int i=1;i <= sink+cnt;i++) chk[i]=0;
	}

	if(ans != n) return !printf("impossible");

	for(int i=1;i<=n;i++){
		for(auto x : v[i]) if(x.cap == 1 && x.val == 1) printf("%d %c %d = %lld\n",a[i],x.d,b[i],A[x.to-sink]);
	}
}
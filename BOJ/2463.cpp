#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge{
	int s, e, v;
	bool operator < (const Edge &o) const{
		return v > o.v;
	}
}a[100100];
int n, m, par[100100];
ll ans, mod = 1e9, sum, sz[100100];
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) par[i] = i, sz[i] = 1;
	for(int i=1;i<=m;i++) scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].v);
	for(int i=1;i<=m;i++) sum += a[i].v;
	sort(a+1, a+1+m);
	
	for(int i=1;i<=m;i++){
		int s = f(a[i].s), e = f(a[i].e);
		if(s != e){
			(ans += sz[s] * sz[e] % mod * sum % mod) %= mod;
			if(sz[s] > sz[e]) swap(s, e);
			sz[e] += sz[s];
			par[s] = e;
		}
		sum -= a[i].v;
	}
	printf("%lld",ans);
}
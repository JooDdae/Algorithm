#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int f, s, c;
	bool operator < (const edge &o) const{
		return c < o.c;
	}
}e[200200];
int n, m, mn, ans = INT_MAX, fl, par[50505], lev[50505], to[50505][20], chk[200200], cnt;
pair<int,int> mx[50505][20];
vector<pair<int,int>> v[50505];

int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}

void dfs(int cur, int par){
	lev[cur] = lev[par] + 1;
	for(auto nxt : v[cur]) if(nxt.first != par){
		to[nxt.first][0] = cur;
		mx[nxt.first][0] = {nxt.second, -1};
		dfs(nxt.first, cur);
	}
}

pair<int,int> find_max(pair<int,int> p1, pair<int,int> p2){
	vector<int> V = {p1.first, p1.second, p2.first, p2.second};
	int mx1 = -2, mx2 = -3;
	for(int u : V){
		if(u > mx1){
			mx2 = mx1;
			mx1 = u;
		}else if(u > mx2 && mx1 > u){
			mx2 = u;
		}
	}
	return {mx1, mx2};
}

pair<int,int> lca(int a, int b){
	pair<int,int> re = {-2, -3};
	if(lev[a] < lev[b]) swap(a, b);
	for(int i=0;i<=17;i++) if((1<<i) & (lev[a]-lev[b])) re = find_max(re, mx[a][i]), a = to[a][i];
	if(a == b) return re;
	for(int i=17;i>=0;i--) if(to[a][i] != to[b][i]) re = find_max(re, find_max(mx[a][i], mx[b][i])), a = to[a][i], b = to[b][i];
	return find_max(re, find_max(mx[a][0], mx[b][0]));
}

signed main(){
	scanf("%lld %lld",&n,&m);
	if(m < n) return !printf("-1");

	for(int i=1;i<=n;i++) par[i] = i;
	for(int i=1;i<=m;i++) scanf("%lld %lld %lld",&e[i].f,&e[i].s,&e[i].c);

	sort(e+1, e+1+m);
	for(int i=1;i<=m;i++){
		int a = f(e[i].f), b = f(e[i].s);
		if(a != b){
			par[a] = b;
			mn += e[i].c;
			v[e[i].f].push_back({e[i].s, e[i].c});
			v[e[i].s].push_back({e[i].f, e[i].c});
			chk[i] = 1;
			cnt++;
		}
	}
	if(cnt != n-1) return !printf("-1");

	for(int j=0;j<=17;j++) for(int i=0;i<=n;i++) mx[i][j] = {-1, -1};
	dfs(1, 0);
	for(int j=1;j<=17;j++) for(int i=1;i<=n;i++) mx[i][j] = find_max(mx[i][j-1], mx[to[i][j-1]][j-1]), to[i][j] = to[to[i][j-1]][j-1];

	for(int i=1;i<=m;i++){
		if(chk[i]) continue;

		pair<int,int> p = lca(e[i].f, e[i].s);
		if(p.first > -1 && 0 < e[i].c - p.first) fl = 1, ans = min(ans, mn + e[i].c - p.first);
		if(p.second > -1 && 0 < e[i].c - p.second) fl = 1, ans = min(ans, mn + e[i].c - p.second);
	}

	printf("%lld",fl ? ans : -1);
}
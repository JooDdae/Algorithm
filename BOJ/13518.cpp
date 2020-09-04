#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int l, r, id, p;
	bool operator < (const node &a) const{
		return make_pair(l>>9, r) < make_pair(a.l>>9, a.r);
	}
}q[100100];
int n, m, a[100100], chk[1001001], cnt[100100], cn, in[100100], out[100100], b[200200], parse[20][200200], lev[200200], ans[100100];
vector<int> v[100100];
void dfs(int u, int p){
	parse[0][u] = p;
	lev[u] = lev[p]+1;
	in[u] = ++cn;
	b[cn] = u;
	for(int x : v[u]) if(x != p) dfs(x, u);
	out[u] = ++cn;
	b[cn] = u;
}
int lca(int a, int b){
	if(lev[a] > lev[b]) swap(a, b);
	for(int i=18;i>=0;i--) if(((lev[b]-lev[a])>>i) & 1) b = parse[i][b];
	if(a == b) return a;
	for(int i=18;i>=0;i--) if(parse[i][a] != parse[i][b]) a = parse[i][a], b = parse[i][b];
	return parse[0][a];
}
int f(int a, int b){
	if(a % 2) return (chk[b]++ == 0) ? 1 : 0;
	return (--chk[b] == 0) ? -1 : 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	for(int i=1;i<=18;i++) for(int j=1;j<=n;j++) parse[i][j] = parse[i-1][parse[i-1][j]];
	cin >> m;
	for(int i=1;i<=m;i++){
		int c, d; cin >> c >> d;
		if(in[c] > in[d]) swap(c, d);
		int e = lca(c, d);
		if(e == c) q[i].l = in[c], q[i].r = in[d];
		else q[i].l = out[c], q[i].r = in[d], q[i].p = e;
		q[i].id = i;
	}
	sort(q+1, q+1+m);
	int l = 1, r = 0 , c = 0;
	for(int i=1;i<=m;i++){
    	while(l<q[i].l) c += f(++cnt[b[l]], a[b[l]]), l++;
    	while(r<q[i].r) c += f(++cnt[b[r+1]], a[b[r+1]]), r++;
    	while(l>q[i].l) c += f(++cnt[b[l-1]], a[b[l-1]]), l--;
    	while(r>q[i].r) c += f(++cnt[b[r]], a[b[r]]), r--;

    	if(q[i].p && chk[a[q[i].p]]++ == 0) c++;
    	ans[q[i].id] = c;
    	if(q[i].p && --chk[a[q[i].p]] == 0) c--;
	}

	for(int i=1;i<=m;i++) cout << ans[i] << '\n';
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, col[100100], par[100100], dead[100100], sz[100100], INF = 1e9, sp[20][100100], lev[100100];
vector<int> v[100100];
multiset<int> s[100100];

int find_sz(int u, int p = 0){
    sz[u] = 1;
    for(int x : v[u]) if(!dead[x] && x != p) sz[u] += find_sz(x, u);
    return sz[u];
}

int centroid(int u){
    int s = find_sz(u);

    int l = 0;
    while(1){
        int w = 0, mx = 0;
        for(int x : v[u]) if(!dead[x] && x != l && mx < sz[x]) w = x, mx = sz[x];
        if(mx * 2 <= s) return u;
        l = u, u = w;
    }
}

void find_centroid(int u = 1, int p = 0){
    dead[u = centroid(u)] = 1;
    par[u] = p;
    for(int x : v[u]) if(!dead[x]) find_centroid(x, u);
}

void dfs(int u = 1, int p = 0){
    lev[u] = lev[p] + 1;
    sp[0][u] = p;
    for(int x : v[u]) if(!lev[x]) dfs(x, u);
}

int lca(int a, int b){
    if(lev[a] < lev[b]) swap(a, b);
    for(int i=0;i<=18;i++) if((1 << i) & (lev[a] - lev[b])) a = sp[i][a];
    if(a == b) return a;
    for(int i=18;i>=0;i--) if(sp[i][a] != sp[i][b]) a = sp[i][a], b = sp[i][b];
    return sp[0][a];
}

int find_dist(int a, int b){
    return lev[a] + lev[b] - lev[lca(a, b)] * 2;
}

void update(int u){
    col[u] = !col[u];

    int x = u;
    while(x){
        int d = find_dist(u, x);
        if(col[u]) s[x].insert(d);
        else s[x].erase(s[x].find(d));
        x = par[x];
    }
}

int find(int u){
    int mn = INF;

    int x = u;
    while(x){
        if(!s[x].empty()) mn = min(mn, find_dist(u, x) + *s[x].begin());
        x = par[x];
    }

    return mn == INF ? -1 : mn;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }
    find_centroid();
    dfs();
    for(int i=1;i<=18;i++) for(int j=1;j<=n;j++) sp[i][j] = sp[i-1][sp[i-1][j]];

    cin >> m;
    while(m--){
        int q, x; cin >> q >> x;
        if(q == 1){
            update(x);
        }else{
            cout << find(x) << "\n";
        }
    }
}
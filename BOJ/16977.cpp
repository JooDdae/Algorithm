#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define qmid ((q[i].l+q[i].r)>>1)
#define mid ((l+r)>>1)
struct node{
	int lm, rm, mx, l, r, a;
}tree[400400];
struct query{
    int s, e, w, l, r, id;
    bool operator < (const query &o) const{
        return (l+r)/2 > (o.l+o.r)/2;
    }
}q[100100];
int n, m, ans[100100], INF = 1e9;
pair<int,int> h[100100];
node merge(node a, node b){
	return {a.lm + (a.a && b.l ? b.lm : 0), b.rm + (a.r && b.a ? a.rm : 0), max({a.mx, b.mx, a.r&&b.l?a.rm+b.lm:0}), a.l, b.r, a.a && b.a};
}
void update(int node, int l, int r, int id, int val){
    if(r < id || id < l) return;
    if(l == r){
        tree[node] = {val, val, val, 1, 1, 1};
        return;
    }
    update(node*2, l, mid, id, val), update(node*2+1, mid+1, r, id, val);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}
node find(int node, int l, int r, int nl, int nr){
    if(r < nl || nr < l) return {0, 0, 0, 0};
    if(nl <= l && r <= nr) return tree[node];
    return merge(find(node*2, l, mid, nl, nr), find(node*2+1, mid+1, r, nl, nr));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i].first), h[i].second = i;
    sort(h+1, h+1+n, greater<>());
	scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d %d %d",&q[i].s,&q[i].e,&q[i].w), q[i].l = 1, q[i].r = h[1].first, q[i].id = i;
 
    int flag = 1;
    while(flag--){
        for(int i=1;i<=4*n;i++) tree[i] = {0, 0, 0, 0, 0, 0};
        sort(q+1, q+1+m);
        for(int i=1,j=1;i<=m;i++){
            if(q[i].l > q[i].r) continue;
            flag = 1;
 
            while(j<=n && h[j].first >= qmid){
                update(1, 1, n, h[j].second, 1);
                j++;
            }
 
			if(find(1, 1, n, q[i].s, q[i].e).mx >= q[i].w) q[i].l = qmid+1;
			else q[i].r = qmid-1;
        }
    }
 
    for(int i=1;i<=m;i++) ans[q[i].id] = q[i].l - 1;
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
}
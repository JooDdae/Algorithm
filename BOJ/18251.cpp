#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct Node{
    ll l, r, mx, sum;
}tree[1201200];
int n, a[300300], x[300300], y[300300], cnt, b[300300];
ll ans = -1e9, INF = 1e9;

void dfs(int node, int h){
    if(node > n) return;
    y[node] = h;

    dfs(node*2, h+1);
    x[node] = ++cnt;
    b[x[node]] = a[node];
    dfs(node*2+1, h+1);
}
void update(int node, int l, int r, int id, ll val){
    if(id<l || r<id) return;
    if(l == r){
        tree[node] = {val, val, val, val};
        return;
    }
    update(node*2, l, mid, id, val), update(node*2+1, mid+1, r, id, val);
    Node L = tree[node*2], R = tree[node*2+1];
    tree[node] = {max(L.l, L.sum+R.l), max(R.r, L.r+R.sum), max({L.mx, R.mx, L.r + R.l, L.sum + R.sum}), L.sum + R.sum};
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    if(*max_element(a+1, a+1+n) <= 0) return !printf("%d",*max_element(a+1, a+1+n));
    dfs(1, 1);
    int i = 1;
    while(i <= n){
        int j = i;
        while(j <= n){
            int Y = y[j];
            while(Y == y[j]){
                update(1, 1, n, x[j], a[j]);
                j++;
            }
            ans = max(ans, tree[1].mx);
        }
        int Y = y[i];
        while(Y == y[i]) i++;
        for(int i=1;i<=4*n;i++) tree[i] = {0, 0, 0, 0};
    }
    printf("%lld",ans);
}
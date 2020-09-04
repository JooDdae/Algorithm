#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)>>1)
struct node{
    int mx, o, z;
}tree[1600800];
int lo[1600800], lz[1600800], ar[200200], n, q, mask = (1<<19)-1;

node merge(node a, node b){
    return {max(a.mx, b.mx), a.o & b.o, a.z & b.z};
}

node build(int id, int l, int r){
    if(l == r) return tree[id] = {ar[l], ar[l], mask - ar[l]};
    return tree[id] = merge(build(id*2, l, mid), build(id*2+1, mid+1, r));
}

void lazy_update(int id, int l, int r){
    if(l > r) return;

    tree[id].mx |= lo[id];
    tree[id].o |= lo[id];
    tree[id].z -= tree[id].z & lo[id];

    tree[id].mx = (tree[id].mx & (mask - lz[id]));
    tree[id].z |= lz[id];
    tree[id].o -= tree[id].o & lz[id];

    if(l != r) for(auto jd : {id*2, id*2+1}){
        lz[jd] = (lz[jd] & (mask - lo[id]));
        lo[jd] = (lo[jd] & (mask - lz[id]));

        lz[jd] |= lz[id];
        lo[jd] |= lo[id];
    }

    lz[id] = lo[id] = 0;
}

void update_and(int id, int l, int r, int nl, int nr, int val){
    lazy_update(id, l, r);
    if(nr < l || r < nl || l > r) return;
    val -= tree[id].z & val;

    if(nl <= l && r <= nr && (tree[id].o & val)){
        lz[id] = tree[id].o & val;
        val -= tree[id].o & val;
        lazy_update(id, l, r);
    }
    if(!val) return;

    update_and(id*2, l, mid, nl, nr, val);
    update_and(id*2+1, mid+1, r, nl, nr, val);
    if(l != r) tree[id] = merge(tree[id*2], tree[id*2+1]);
}

void update_or(int id, int l, int r, int nl, int nr, int val){
    lazy_update(id, l, r);
    if(nr < l || r < nl || l > r) return;
    val -= tree[id].o & val;

    if(nl <= l && r <= nr && (tree[id].z & val)){
        lo[id] = tree[id].z & val;
        val -= tree[id].z & val;
        lazy_update(id, l, r);
    }
    if(!val) return;

    update_or(id*2, l, mid, nl, nr, val);
    update_or(id*2+1, mid+1, r, nl, nr, val);
    if(l != r) tree[id] = merge(tree[id*2], tree[id*2+1]);
}

int find_max(int id, int l, int r, int nl, int nr){
    lazy_update(id, l, r);
    if(nr < l || r < nl) return 0;
    if(nl <= l && r <= nr) return tree[id].mx;
    return max(find_max(id*2, l, mid, nl, nr), find_max(id*2+1, mid+1, r, nl, nr));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",ar+i);
    build(1, 1, n);
    scanf("%d",&q);
    while(q--){
        int a, b, c, d; scanf("%d",&a);
        if(a == 1){
            scanf("%d %d %d",&b,&c,&d);
            update_and(1, 1, n, b, c, mask-d);
        }
        if(a == 2){
            scanf("%d %d %d",&b,&c,&d);
            update_or(1, 1, n, b, c, d);
        }
        if(a == 3){
            scanf("%d %d",&b,&c);
            printf("%d\n",find_max(1, 1, n, b, c));
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct query{
    int l, r, mid, x, y, z;
    bool operator < (const query &o)const{
        return mid < o.mid;
    }
}q[200200];
int N,M,K,Q,ride[200200],up[200200],ans[200200],kid[200200],flag=1;
int main(){
    scanf("%d %d %d %d",&N,&M,&K,&Q);
    for(int i=1;i<=M;i++) scanf("%d",ride+i);
    for(int i=1;i<=K;i++) scanf("%d",up+i);
    for(int i=1;i<=Q;i++){
        scanf("%d %d %d",&q[i].x,&q[i].y,&q[i].z);
        q[i].l = 1, q[i].r = K, q[i].mid = (q[i].l + q[i].r) / 2;
    }

    while(flag--){
        for(int i=1;i<=N;i++) kid[i] = 0;

        sort(q+1, q+1+Q);
        for(int i=1,j=1;i<=Q;i++){
            if(q[i].l > q[i].r) continue;
            flag = 1;

            while(j<=K && j<=q[i].mid){
                kid[up[j]]++;
                j++;
            }

            if(kid[q[i].x] + kid[q[i].y] >= ride[q[i].z]) q[i].r = q[i].mid - 1;
            else q[i].l = q[i].mid + 1;
            q[i].mid = (q[i].l + q[i].r) / 2;
        }
    }

    for(int i=1;i<=Q;i++) ans[q[i].l]++;
    for(int i=1;i<=K;i++) printf("%d\n",ans[i]+=ans[i-1]);
}
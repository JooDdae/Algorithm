#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
    int x,y;
    bool operator < (const point &a)const{
        return tie(x,y) < tie(a.x,a.y);
    }
}in[202020];
int n;
ll tree[2][404040],mod=1e9+7,ans;
void up(int t,int bit,ll val){
    while(bit <= 400001){
        tree[t][bit] += val;
        bit += bit&(-bit);
    }
}
ll f(int t,int bit){
    ll re = 0;
    while(bit){
        re += tree[t][bit];
        bit -= bit&(-bit);
    }
    return re;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&in[i].x,&in[i].y);
    for(int i=1;i<=n;i++) in[i].x+=200001,in[i].y+=200001;
    sort(in+1,in+1+n);
    int cur=0;
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(in[i].x > cur){
            for(int nxt : v){
                up(1,nxt,f(0,400001)-f(0,nxt));
                up(0,nxt,1);
            }
            v.clear();
            cur = in[i].x;
        }
        (ans+=f(1,in[i].y-1))%=mod;
        v.push_back(in[i].y);
    }
    printf("%lld",ans);
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((l+r)/2)
int t,n,m,chk[101010],cnt;
ll arr[101010],l,r;
vector<int> v[101010];
ll dfs(int cur){
    chk[cur] = 1;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll re = arr[cur];
    for(int nxt : v[cur]){
        if(chk[nxt]) continue;
        pq.push(dfs(nxt));
    }
    while(!pq.empty() && re + pq.top() <= mid){
        re += pq.top();
        pq.pop();
    }
    cnt += pq.size();

    return re;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        for(int i=1;i<=n;i++) r+=arr[i];
        for(int i=1;i<=n;i++) l=max(l,arr[i]);
        for(int i=1;i<n;i++){
            int a,b; scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        while(l<=r){
            for(int i=1;i<=n;i++) chk[i] = 0;
            cnt = 0;
            dfs(1);
            if(cnt > m) l = mid+1;
            else r = mid-1;
        }
        printf("%lld\n",l);
        for(int i=1;i<=n;i++) v[i].clear();
    }
}

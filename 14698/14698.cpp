#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
const ll mod = 1000000007;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main(){
    scanf("%d",&t);
    while(t--){
        ll ans = 1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            ll a; scanf("%lld",&a);
            pq.push(a);
        }

        while(pq.size() != 1){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();

            ans = (a*b%mod*ans)%mod;
            pq.push(a*b);
        }
        pq.pop();

        printf("%lld\n",ans);
    }
}

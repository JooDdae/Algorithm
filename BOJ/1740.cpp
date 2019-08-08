#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,sum=1,n;
int main(){
    scanf("%lld",&n);
    for(int i=0;(1ll<<i)<=n;i++,sum*=3) if(n&(1ll<<i)) ans+=sum;
    printf("%lld",ans);
}
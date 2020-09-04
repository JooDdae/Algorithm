#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll ans, mod = 1e9+7;
ll f(ll a, int b){
	if(b < 1) return 1;
	ll k = f(a, b/2);
	return k * k % mod * (b%2 ? a : 1) % mod;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		(ans += f(2, b-1) * b % mod * a) %= mod;
	}
	printf("%lld",ans);
}
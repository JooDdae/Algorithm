#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll mod = 1e9+7;
ll f(ll a, int b){
	if(b <= 0) return 1;
	ll f2 = f(a, b/2);
	return f2 * f2 % mod * (b&1 ? a : 1) % mod;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",f(2,n-2));
	}
}
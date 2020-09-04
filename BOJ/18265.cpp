#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
	scanf("%lld",&n); n--;
	ll l = 1, r = 1e18;
	while(l <= r){
		ll mid = (l+r)>>1;
		ll m = mid - mid/3 - mid/5 + mid/15;
		if(m <= n) l = mid+1;
		else if(m > n) r = mid-1;
	}
	printf("%lld",l);
}
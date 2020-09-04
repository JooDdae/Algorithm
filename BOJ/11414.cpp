#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, mnx = 1, mnn = 1e18, l, f;
vector<ll> v;
int main(){
	scanf("%lld %lld",&a,&b);
	if(a > b) swap(a, b);
	for(ll i=1;i*i<=b-a;i++) if((b-a)%i == 0) v.push_back(i), v.push_back((b-a)/i);
	sort(v.begin(), v.end());
	for(auto x : v){
		l = (a/x+1) * x;
		f = l * (b+l-a) / __gcd(l, b+l-a);
		if(f < mnn) mnx = l-a, mnn = f;
	}
	printf("%lld",mnx);
}
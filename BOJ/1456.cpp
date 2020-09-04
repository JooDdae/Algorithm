#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, ans;
bool chk[10001000];
int main(){
	scanf("%lld %lld",&a,&b);
	for(ll i=2;i*i<=b;i++){
		if(chk[i]) continue;
		__int128 c = i*i;
		while(c <= b) ans += (c>=a), c*=i;
		for(ll j=i+i;j*j<=b;j+=i) chk[j] = true;
	}
	printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, a[101];
int main(){
	scanf("%d",&t);
	while(t--){
		ll ans = 0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans += __gcd(a[i], a[j]);
		printf("%lld\n",ans);
	}
}
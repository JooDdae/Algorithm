#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s, ans, m;
map<ll,int> mp;
int main(){
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		mp[s]++;
		int a; scanf("%d",&a);
		s += a;
		ans += mp[s-m];
	}
	printf("%lld",ans);
}
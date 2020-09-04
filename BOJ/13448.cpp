#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll m, p, r;
	bool operator < (const node &a) const{
		return a.r*p > r*a.p;
	}
}p[55];
int n, t;
ll dp[101010], ans;
int main(){
	scanf("%d %d",&n,&t);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i].m);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i].p);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i].r);
	sort(p+1, p+1+n);
	for(int i=1;i<=n;i++) for(int j=t;j>=p[i].r;j--) dp[j] = max(dp[j], dp[j-p[i].r] + p[i].m - p[i].p*j);
	for(int i=1;i<=t;i++) ans = max(ans, dp[i]);
	printf("%lld",ans);
}
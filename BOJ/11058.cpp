#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[111];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		dp[i] = dp[i-1] + 1;
		for(int j=1;j<=i-3;j++) dp[i] = max(dp[i], dp[i-j-2] * (j+1));
	}
	printf("%lld",dp[n]);
}
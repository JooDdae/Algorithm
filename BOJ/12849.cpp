#include<bits/stdc++.h>
using namespace std;
long long dp[8][100100], n, mod=1e9+7;
int main(){
	scanf("%lld",&n);
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[0][i] = dp[1][i-1] + dp[2][i-1];
		dp[1][i] = dp[0][i-1] + dp[2][i-1] + dp[3][i-1];
		dp[2][i] = dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1];
		dp[3][i] = dp[1][i-1] + dp[2][i-1] + dp[4][i-1] + dp[5][i-1];
		dp[4][i] = dp[2][i-1] + dp[3][i-1] + dp[5][i-1] + dp[7][i-1];
		dp[5][i] = dp[3][i-1] + dp[4][i-1] + dp[6][i-1];
		dp[6][i] = dp[5][i-1] + dp[7][i-1];
		dp[7][i] = dp[4][i-1] + dp[6][i-1];
		for(int j=0;j<8;j++) dp[j][i] %= mod;
	}
	printf("%lld",dp[0][n]);
}
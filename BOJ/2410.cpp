#include<bits/stdc++.h>
using namespace std;
int dp[1001001], n, mod = 1e9;
int main(){
	scanf("%d",&n);
	dp[0] = 1;
	for(int i=1;i<=n;i*=2) for(int j=i;j<=n;j++) (dp[j] += dp[j-i]) %= mod;
	printf("%d",dp[n]);
}
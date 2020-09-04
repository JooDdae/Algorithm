#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[1001001];
int main(){
	scanf("%d",&n);
	dp[1] = 0;
	dp[2] = 1;
	for(int i=3;i<=n;i++) dp[i] = 1ll * (i-1) * (dp[i-1] + dp[i-2]) % 1000000000;
	printf("%d",dp[n]);
}
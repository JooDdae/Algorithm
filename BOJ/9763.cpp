#include<bits/stdc++.h>
using namespace std;
int t, n, dp[2020], mod = 100999;
int main(){
	dp[0] = 1;
	for(int i=1;i<=2000;i++) for(int j=2000;j>=i;j--) (dp[j] += dp[j-i]) %= mod;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}
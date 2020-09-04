#include<bits/stdc++.h>
using namespace std;
int t, n, dp[10010];
int main(){
	dp[0] = 1;
	for(int j=1;j<=3;j++) for(int i=j;i<=10000;i++) dp[i] += dp[i-j];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}
}
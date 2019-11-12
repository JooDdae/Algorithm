#include<bits/stdc++.h>
using namespace std;
int n,dp[50505];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) dp[i] = 1e9;
	for(int i=1;i*i<=n;i++) for(int j=i*i;j<=n;j++) dp[j] = min(dp[j-i*i]+1, dp[j]);
	printf("%d",dp[n]);
}
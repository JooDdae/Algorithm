#include<bits/stdc++.h>
int n,m,dp[100100][11],a[100100][11],ans;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) scanf("%d",a[j]+i);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<=m;k++) dp[i][j] = std::max(dp[i][j], dp[i-1][k] + a[i][j]/(1+(i>1 && j==k)));
	for(int i=1;i<=m;i++) ans = std::max(ans, dp[n][i]);
	printf("%d",ans);
}
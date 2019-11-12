#include<bits/stdc++.h>
using namespace std;
int n,m,mp[1010][1010],dp[1010][1010][3],ans=1e9,dy[3]={-1,0,1};
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<3;k++){
		dp[i][j][k] = 1e9;
		for(int l=0;l<3;l++) if(k != l && j+dy[l]>0 && j+dy[l]<=m) dp[i][j][k] = min(dp[i-1][j+dy[l]][l], dp[i][j][k]);
		dp[i][j][k]+=mp[i][j];
	}
	for(int i=1;i<=m;i++) for(int j=0;j<3;j++) ans = min(ans, dp[n][i][j]);
	printf("%d",ans);
}
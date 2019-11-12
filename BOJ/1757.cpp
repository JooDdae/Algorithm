#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[10505],dp[10505][505],ans;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		dp[i][0] = max(dp[i][0], dp[i-1][0]);
		for(int j=1;j<=m;j++) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[i]);
		for(int j=1;j<=m;j++) dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
	}
	printf("%d",dp[n][0]);
}
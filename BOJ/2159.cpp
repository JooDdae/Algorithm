#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x[100100], y[100100], dx[5]={0,0,1,-1,0},dy[5]={1,-1,0,0,0};
ll dp[100100][5];
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++) scanf("%d %d",x+i,y+i);

	for(int i=0;i<4;i++) dp[0][i] = 1e18;
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++){
			dp[i][j] = 1e18;
			for(int k=0;k<5;k++) dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(x[i-1]+dx[k]-x[i]-dx[j]) + abs(y[i-1]+dy[k]-y[i]-dy[j]));
		}
	}
	printf("%lld",min({dp[n][0],dp[n][1],dp[n][2],dp[n][3],dp[n][4]}));
}
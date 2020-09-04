#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, dp[111][111][2];
int main(){
	dp[0][0][0] = 1;
	for(int i=1;i<=100;i++){
		for(int j=0;j<=100;j++){
			dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0];
			if(j) dp[i][j][1] +=  dp[i-1][j-1][1];
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		printf("%d\n",dp[n][m][0] + dp[n][m][1]);
	}
}
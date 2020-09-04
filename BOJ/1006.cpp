#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, dp[10010][4][3], a[10010][3];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int j=1;j<=2;j++) for(int i=1;i<=n;i++) scanf("%d",a[i]+j);
		a[n+1][1] = a[1][1], a[n+1][2] = a[1][2];

		dp[1][0][1] = dp[1][0][2] = 1;
		dp[1][0][0] = 2 - (a[1][1] + a[1][2] <= m);

		dp[1][1][0] = 1;
		dp[1][1][1] = 0;
		dp[1][1][2] = 1e9;

		dp[1][2][0] = 1;
		dp[1][2][1] = 1e9;
		dp[1][2][2] = 0;

		dp[1][3][1] = dp[1][3][2] = 1e9;
		dp[1][3][0] = 0;

		for(int i=2;i<=n+1;i++){
			for(int j=0;j<=3;j++){
				dp[i][j][1] = dp[i-1][j][0] + 1;
				if(a[i-1][1] + a[i][1] <= m) dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][2] + 1);

				dp[i][j][2] = dp[i-1][j][0] + 1;
				if(a[i-1][2] + a[i][2] <= m) dp[i][j][2] = min(dp[i][j][2], dp[i-1][j][1] + 1);

				dp[i][j][0] = min(dp[i][j][1], dp[i][j][2]) + 1;
				if(a[i][1] + a[i][2] <= m) dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + 1);
				if((i > 2 || !j) && a[i][1] + a[i-1][1] <= m && a[i][2] + a[i-1][2] <= m) dp[i][j][0] = min(dp[i][j][0], dp[i-2][j][0]+2);
			}
		}
		printf("%d\n", min({dp[n][0][0], dp[n+1][1][1], dp[n+1][2][2], dp[n+1][3][0]}));
	}
}
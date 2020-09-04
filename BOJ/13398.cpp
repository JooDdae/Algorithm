#include<bits/stdc++.h>
using namespace std;
int n, dp[100100][2], ans = -1000;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		dp[i][0] = max(dp[i-1][0], 0) + a;
		dp[i][1] = dp[i-1][1] + a;
		if(i > 1) dp[i][1] = max(dp[i][1], dp[i-2][0]+a); 
		ans = max({ans, dp[i][0], dp[i][1]});
	}
	printf("%d",ans);
}
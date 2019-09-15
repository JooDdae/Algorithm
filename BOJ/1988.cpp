#include<bits/stdc++.h>
using namespace std;
int n,m,dp[3030][3030][2];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	for(int j=1;j<m;j++){
    		dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
    		dp[i][j][1] = max(dp[i-1][j-1][0], dp[i-1][j-1][1]+a);
    	}
    }
    printf("%d",max(dp[n][m-1][0],dp[n][m-1][1]));
}
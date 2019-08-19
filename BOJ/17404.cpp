#include<bits/stdc++.h>
using namespace std;
int n,dp[1010][4][4],ans=1e9,a[4];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=3;j++) scanf("%d",&a[j]);
    	for(int j=1;j<=3;j++){
    		for(int k=1;k<=3;k++){
    			dp[i][j][k] = 1e9;
    			if(i == 1 && j != k) continue;
    			for(int l=1;l<=3;l++) if(j!=l) dp[i][j][k] = min(dp[i][j][k], dp[i-1][l][k] + a[j]);
    			if(i==n && j!=k) ans=min(ans, dp[i][j][k]);
    		}
    	}
    }
    printf("%d",ans);
}
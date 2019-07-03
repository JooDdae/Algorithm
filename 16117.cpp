#include <bits/stdc++.h>
using namespace std;
int n,m,mp[2020][2020],dp[2020][2020],ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&mp[i*2][j*2]);
    for(int j=1;j<=2*m+4;j++){
        for(int i=1;i<=2*n+1;i++){
            if(j>1 && i>1) dp[i][j] = max(dp[i][j], dp[i-2][j-2]+mp[i-1][j-1]);
            if(j>1) dp[i][j] = max(dp[i][j], dp[i+2][j-2]+mp[i+1][j-1]);
            if(j>3) dp[i][j] = max(dp[i][j], dp[i][j-4]+mp[i][j-3]+mp[i][j-2]+mp[i][j-1]);
            dp[i][j] += mp[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d",ans);
}

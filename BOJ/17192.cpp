#include<bits/stdc++.h>
using namespace std;
int n,m,arr[404],dp[404][404];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<=n;i++) for(int j=0;j<=m+1;j++) dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        int sum=0,mx=0;
        for(int j=i;j<=n;j++){
            sum += arr[j];
            mx = max(mx, arr[j]);
            for(int k=1;k<=m+1;k++) dp[j][k] = min(dp[j][k], dp[i-1][k-1]+mx*(j-i+1)-sum);
        }
    }
    printf("%d",dp[n][m+1]);
}

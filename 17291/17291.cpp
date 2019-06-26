#include<bits/stdc++.h>
using namespace std;
int n,dp[33];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=4;i++) dp[i]=1;
    for(int i=2;i<=n+1;i++) for(int j=1;j<=4-i%2;j++) dp[i+j] += dp[i];
    printf("%d ",dp[n+1]);
}

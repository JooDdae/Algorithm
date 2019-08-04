#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[1010101],dp2[1010101],mod=1e9+7;
int main(){
    scanf("%d",&n);
    dp[0]=1; dp[1]=2; dp[2]=7; dp[3]=22;
    dp2[3]=1;
    for(int i=4;i<=n;i++){
    	dp2[i]=(dp2[i-1]+dp[i-3])%mod;
    	dp[i]=(dp[i-2]*3+dp[i-1]*2+dp2[i]*2)%mod;
    }
    printf("%lld",dp[n]);
}
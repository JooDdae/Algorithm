#include <bits/stdc++.h>
using namespace std;
long long dp[1000][1000],ans[300],n=300;

int main(){
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int i=1;i<=n/2;i++) dp[i*2][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<=j;k++){
                dp[i+2*k][k] += dp[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) ans[i] += dp[i][j];
    while(1){
        int a; scanf("%d",&a);
        if(!a) return 0;
        printf("%d %lld\n",a,ans[a]);
    }
}

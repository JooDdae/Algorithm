#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n,m,ans,bx,by;
vector<int> dp[305][305];
int main(){
    scanf("%d %d",&n,&m);
    if(n < m) swap(n,m);
    int bit = (1<<m+1)-1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            dp[i][j].resize(1 << m+1);
    }
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<=bit;k++){
                if(j==1 || i==1 || !((k&1)&&(k&(1<<m-1))&&(k&(1<<m))))
                    (dp[i][j][((k<<1)&bit)+1] += dp[bx][by][k]) %= mod;
                (dp[i][j][(k<<1)&bit] += dp[bx][by][k]) %= mod;
            }
            bx=i, by=j;
        }
    }
    for(int i=0;i<=bit;i++) ans = (ans+dp[n][m][i])%mod;
    printf("%d",ans);
}

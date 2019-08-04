#include <bits/stdc++.h>
using namespace std;
const int val[5][5]={
    {10,8,7,5,1},
    {8,6,4,3,1},
    {7,4,3,2,1},
    {5,3,2,2,1},
    {1,1,1,1,0}};
int n,m,bx,by,dp[20][20][1<<14],ans;
char mp[20][20];
int main(){
    scanf("%d %d",&n,&m);
    int bit = (1<<m)-1;
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == 'F') mp[i][j]--;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<(1<<m);k++){
                if(i > 1 && !(k&(1<<m-1))) dp[i][j][((k<<1)&bit)+1] = max(dp[i][j][((k<<1)&bit)+1], dp[bx][by][k] + val[mp[i-1][j]-'A'][mp[i][j]-'A']);
                if(j > 1 && !(k&1)) dp[i][j][((k<<1)&bit)+3] = max(dp[i][j][((k<<1)&bit)+3], dp[bx][by][k] + val[mp[i][j-1]-'A'][mp[i][j]-'A']);
                dp[i][j][(k<<1)&bit] = max(dp[i][j][(k<<1)&bit], dp[bx][by][k]);
            }
            bx=i,by=j;
        }
    }

    for(int i=0;i<(1<<m);i++) ans = max(ans, dp[n][m][i]);
    printf("%d",ans);
}

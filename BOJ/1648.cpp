#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dp[15][15][1<<15],mod=9901,bx,by;
int main(){
    scanf("%d %d",&n,&m);
    int mask = (1<<m)-1;
    dp[0][0][mask] = 1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		for(int k=0;k<=mask;k++){
    			if(k&(1<<(m-1))) (dp[i][j][(k<<1)&mask] += dp[bx][by][k]) %= mod;
    			if(i>1 && !(k&(1<<(m-1)))) (dp[i][j][(k<<1)+1] += dp[bx][by][k]) %= mod;
    			if(j>1 && !(k&1) && (k&(1<<(m-1)))) (dp[i][j][((k<<1)&mask)+3] += dp[bx][by][k]) %= mod;
    		}
    		bx=i,by=j;
    	}
    }
    printf("%d",dp[n][m][mask]);
}
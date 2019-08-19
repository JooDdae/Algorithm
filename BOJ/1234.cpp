#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c;
ll dp[11][101][101][101],ans,f[101][101];
ll C(int a,int b){
	if(b == 0 || a == b) return 1;
	if(f[a][b]) return f[a][b];
	return f[a][b] = C(a-1,b-1) + C(a-1,b);
}
int main(){
    scanf("%d %d %d %d",&n,&a,&b,&c);
    dp[0][a][b][c] = 1;
    for(int i=1;i<=n;i++){
    	for(int j=0;j<=a;j++){
    		for(int k=0;k<=b;k++){
    			for(int l=0;l<=c;l++){
    				if(j+i <= a) dp[i][j][k][l] += dp[i-1][j+i][k][l];
    				if(k+i <= b) dp[i][j][k][l] += dp[i-1][j][k+i][l];
    				if(l+i <= c) dp[i][j][k][l] += dp[i-1][j][k][l+i];
    				if(i%2 == 0){
	    				if(j+i/2 <= a && k+i/2 <= b) dp[i][j][k][l] += dp[i-1][j+i/2][k+i/2][l] * C(i,i/2);
	    				if(j+i/2 <= a && l+i/2 <= c) dp[i][j][k][l] += dp[i-1][j+i/2][k][l+i/2] * C(i,i/2);
	    				if(k+i/2 <= b && l+i/2 <= c) dp[i][j][k][l] += dp[i-1][j][k+i/2][l+i/2] * C(i,i/2);
    				}
    				if(i%3 == 0){
    					if(j+i/3 <= a && k+i/3 <= b && l+i/3 <= c) dp[i][j][k][l] += dp[i-1][j+i/3][k+i/3][l+i/3] * C(i,i/3) * C(i/3*2,i/3);
    				}
    				if(i == n) ans += dp[i][j][k][l];
    			}
    		}
    	}
    }
    printf("%lld",ans);
}
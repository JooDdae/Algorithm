#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,dp[55][55][55][55],mod=1e9+7;
int f(int cnt,int a,int b,int c){
	if(a>A || b>B || c>C) return 0;
	if(cnt == 0) return a==A && b==B && c==C;
	if(dp[cnt][a][b][c] != -1) return dp[cnt][a][b][c];
	int re=0;
	(re += f(cnt-1,a+1,b,c)) %= mod;
	(re += f(cnt-1,a,b+1,c)) %= mod;
	(re += f(cnt-1,a,b,c+1)) %= mod;
	(re += f(cnt-1,a+1,b+1,c)) %= mod;
	(re += f(cnt-1,a+1,b,c+1)) %= mod;
	(re += f(cnt-1,a,b+1,c+1)) %= mod;
	(re += f(cnt-1,a+1,b+1,c+1)) %= mod;
	return dp[cnt][a][b][c] = re;
}
int main(){
    scanf("%d %d %d %d",&n,&A,&B,&C);
    for(int i=1;i<=n;i++) for(int j=0;j<=A;j++) for(int k=0;k<=B;k++) for(int l=0;l<=C;l++) dp[i][j][k][l] = -1;
    printf("%d",f(n,0,0,0));
}
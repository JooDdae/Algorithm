#include<bits/stdc++.h>
using namespace std;
int t,n,x[600],y[600],chk[;
double dp[512][512];
double dist(int a,int b){
	return hypot(x[a]-x[b], y[a]-y[b]);
}
double f(int a,int b){
	if(a==n) return dist(b,n);
	if(b==n) return dist(a,n);
	if(dp[a][b] > -1) return dp[a][b];
	int nxt = max(a,b)+1;
	return dp[a][b] = min(f(nxt,b)+dist(a,nxt), f(a,nxt)+dist(b,nxt));;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chk[i][j]=0;
    	printf("%.10f\n",f(1,1));
    }
}
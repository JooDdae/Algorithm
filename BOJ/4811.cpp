#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[33][33];
int n;
ll f(int a, int b){
	if(a == 0 && b == 0) return 1;
	if(a < 0 || b < 0) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	return dp[a][b] = f(a-1, b+1) + f(a, b-1);
}
int main(){
	while(1){
		scanf("%d",&n);
		if(!n) break;
		for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -1;
		printf("%lld\n",f(n, 0));
	}
}
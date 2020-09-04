#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, dp[40404][5], mx = 1<<15;
int main(){
	dp[0][0] = 1;
	for(int i=1;i*i<=mx;i++) for(int j=i*i;j<=mx;j++) for(int k=1;k<=4;k++) dp[j][k] += dp[j-i*i][k-1];
	while(1){
		scanf("%d",&n);
		if(!n) break;
		printf("%d\n",dp[n][1]+dp[n][2]+dp[n][3]+dp[n][4]);
	}
}
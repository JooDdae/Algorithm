#include<bits/stdc++.h>
using namespace std;
int n, hp[4], dp[66][66][66][66];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",hp+i);
	dp[0][hp[1]][hp[2]][hp[3]] = 1;
	for(int i=1;;i++){
		for(int j=0;j<=hp[1];j++){
			for(int k=0;k<=hp[2];k++){
				for(int l=0;l<=hp[3];l++){
					if(dp[i-1][j][k][l]){
						dp[i][max(0, j-9)][max(0, k-3)][max(0, l-1)] = 1;
						dp[i][max(0, j-3)][max(0, k-9)][max(0, l-1)] = 1;
						dp[i][max(0, j-1)][max(0, k-3)][max(0, l-9)] = 1;
						dp[i][max(0, j-1)][max(0, k-9)][max(0, l-3)] = 1;
						dp[i][max(0, j-3)][max(0, k-1)][max(0, l-9)] = 1;
						dp[i][max(0, j-9)][max(0, k-1)][max(0, l-3)] = 1;
					}
				}
			}
		}
		if(dp[i][0][0][0]) return !printf("%d",i);
	}
}
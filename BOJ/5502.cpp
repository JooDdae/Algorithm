#include<bits/stdc++.h>
using namespace std;
int n,dp[5050][5050];
char s[5050];
int main(){
	scanf("%d %s",&n,s+1);
	for(int i=1;i<n;i++) dp[i][i+1] = s[i] != s[i+1];
	for(int l=3;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j = i+l-1;
			dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
			if(s[i] == s[j]) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
		}
	}
	printf("%d",dp[1][n]);
}
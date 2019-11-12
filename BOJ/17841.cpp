#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,len[100100][5],mod=1e9+7,dp[6];
char s[30],S[10]="UNIST!";
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);

		for(int j=0;j<5;j++){
			int fl = 0;
			while(s[fl] == S[j + fl]) fl++;
			len[i][j] = fl;
		}
	}

	dp[0] = 1;
	for(int j=1;j<=n;j++){
		for(int i=0;i<5;i++){
			int l = len[j][i];
			for(int k=1;k<=l;k++) (dp[i+k] += dp[i]) %= mod;
		}
	}
	
	printf("%d",dp[5]);
}
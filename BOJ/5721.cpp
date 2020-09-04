#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, dp[100100], dp2[100100], in[100100];
int main(){
	while(1){
		scanf("%d %d",&n,&m);
		if(!n && !m) break;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) scanf("%d",in+j);
			dp2[1] = in[1];
			for(int j=2;j<=m;j++) dp2[j] = max(dp2[j-1], dp2[j-2] + in[j]);
			if(i == 1) dp[i] = dp2[m];
			else dp[i] = max(dp[i-1], dp[i-2] + dp2[m]);
		}
		printf("%d\n",dp[n]);
	}
}
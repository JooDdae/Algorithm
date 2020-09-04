#include<bits/stdc++.h>
using namespace std;
int n, dp[1500150];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		dp[i] = max(dp[i], dp[i-1]);
		dp[i+a] = max(dp[i+a], dp[i]+b);
	}
	printf("%d",max(dp[n], dp[n+1]));
}
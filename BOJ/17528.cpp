#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sum,dp[300][90000],ans = 1e9;
pair<int,int> p[300];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i].first >> p[i].second;
    sort(p+1, p+1+n);
	for(int i=1;i<=250*250;i++) dp[0][i] = 1e9;

	for(int i=1;i<=n;i++){
		sum += p[i].first;
		for(int j=sum;j>=0;j--){
			dp[i][j] = dp[i-1][j] + p[i].second;
			if(j >= p[i].first) dp[i][j] = min(dp[i][j], dp[i-1][j-p[i].first]);
		}
	}
	
	for(int i=0;i<=sum;i++) ans = min(ans, max(i, dp[n][i]));
	cout << ans;
}
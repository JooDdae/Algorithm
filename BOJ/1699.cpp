#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,dp[101010];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) dp[i] = 1e9;
    for(int i=1;i*i<=n;i++) for(int j=i*i;j<=n;j++) dp[j] = min(dp[j], dp[j-i*i]+1);
	cout << dp[n];
}
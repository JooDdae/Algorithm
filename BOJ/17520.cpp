#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,dp[101010][3],mod=16769023;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
    	dp[i][1] = dp[i][2] = dp[i-1][0];
    	dp[i][0] = (dp[i-1][1] + dp[i-1][2]) % mod;
    }
   	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
}
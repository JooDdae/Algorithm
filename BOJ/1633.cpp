#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int a,b,dp[1010][20][20];
int main(){
    while(~scanf("%d %d",&a,&b)) v.push_back({a,b});
    dp[0][1][0] = v[0].first;
    dp[0][0][1] = v[0].second;
    for(int i=1;i<v.size();i++){
    	for(int j=15;j>=0;j--){
    		for(int k=15;k>=0;k--){
    			dp[i][j][k] = dp[i-1][j][k];
    			if(k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + v[i].second);
    			if(j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + v[i].first);
    		}
    	}
    }
    printf("%d",dp[v.size()-1][15][15]);
}
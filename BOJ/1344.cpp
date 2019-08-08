#include<bits/stdc++.h>
using namespace std;
double a,b,dp[20][20][20],sum;
bool chk[20];
int main(){
	chk[2]=chk[3]=chk[5]=chk[7]=chk[11]=chk[13]=chk[17]=true;
    scanf("%lf %lf",&a,&b);
    a/=100,b/=100;
    dp[0][0][0] = 1;
    for(int t=0;t<18;t++){
    	for(int i=0;i<=18;i++){
    		for(int j=0;j<=18;j++){
    			dp[t+1][i][j] += dp[t][i][j] * ((1.0-a)*(1.0-b));
    			dp[t+1][i+1][j] += dp[t][i][j] * ((1.0-a)*b);
    			dp[t+1][i][j+1] += dp[t][i][j] * (a*(1.0-b));
    			dp[t+1][i+1][j+1] += dp[t][i][j] * (a*b);
    		}
    	}
    }
    for(int i=0;i<=18;i++){
    	for(int j=0;j<=18;j++){
    		if(chk[i] || chk[j]){
    			sum += dp[18][i][j];
    		}
    	}
    }
    printf("%.10f",sum);
}
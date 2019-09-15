#include<bits/stdc++.h>
using namespace std;
int t,n,m,dp[11][11][1<<12];
char mp[20][20];
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d",&n,&m);
    	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    	int mask = (1<<(m+2))-1;
    	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<=mask;k++) dp[i][j][k] = 0;
    	int lx=0,ly=0;
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=m;j++){
    			for(int k=0;k<=mask;k++){
    				dp[i][j][(k<<1)&mask] = max(dp[i][j][(k<<1)&mask], dp[lx][ly][k]);
    				if(mp[i][j] == '.'){
    					if(m == 1) dp[i][j][((k<<1)&mask)+1] = max(dp[i][j][((k<<1)&mask)+1], dp[lx][ly][k]+1);
    					else if(j == 1){
    						if(!(k&(1<<(m-2)))) dp[i][j][((k<<1)&mask)+1] = max(dp[i][j][((k<<1)&mask)+1], dp[lx][ly][k]+1);
    					}else if(j == m){
    						if(!(k&(1<<m)) && !(k&1)) dp[i][j][((k<<1)&mask)+1] = max(dp[i][j][((k<<1)&mask)+1], dp[lx][ly][k]+1);
    					}else{
    						if(!(k&1) && !(k&(1<<m)) && !(k&(1<<(m-2)))) dp[i][j][((k<<1)&mask)+1] = max(dp[i][j][((k<<1)&mask)+1], dp[lx][ly][k]+1);
    					}
    				}
    			}
    			lx=i,ly=j;
    		}
    	} 
    	int mx=0;
    	for(int k=0;k<=mask;k++) mx = max(mx, dp[n][m][k]);
    	printf("%d\n",mx);
    }
}
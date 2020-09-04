#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,x[111],y[111],dist[111][111];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++) scanf("%d %d",x+i,y+i);
		for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dist[i][j] = abs(x[i] - x[j]) +  abs(y[i] - y[j]);
		for(int k=0;k<=n+1;k++) for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
		puts(dist[0][n+1]<=1000?"happy":"sad");
	}
}
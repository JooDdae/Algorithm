#include<bits/stdc++.h>
using namespace std;
int n,m,dist[101][101],mn=2e9,mnx;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j] = 1e9;
    while(m--){
    	int a,b; scanf("%d %d",&a,&b);
    	dist[a][b] = 1;
    	dist[b][a] = 1;
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i=1;i<=n;i++){
    	int cnt=0;
    	for(int j=1;j<=n;j++) cnt += dist[i][j];
    	if(cnt < mn) mn=cnt,mnx=i;
    }
    printf("%d",mnx);
}
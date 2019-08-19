#include<bits/stdc++.h>
using namespace std;
int n,m,dist[101][101];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j] = 1e9;
    while(m--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	dist[a][b] = min(dist[a][b], c);
    }
    for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++) printf("%d ",dist[i][j]==1e9?0:dist[i][j]);
    	puts("");
    }
}
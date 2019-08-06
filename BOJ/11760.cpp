#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,dist[101][101],INF = 1e9,to[101][101];
queue<int> q;
int f(int x,int y){
	q.push(x);
	if(x == y) return 1;
	return f(to[x][y], y) + 1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j] = INF;
    while(m--){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	dist[a][b] = min(dist[a][b],c);
    	to[a][b] = b;
    }
    for(int k=1;k<=n;k++){
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=n;j++){
    			if(i!=j && dist[i][k]+dist[k][j] < dist[i][j]){
    				dist[i][j] = dist[i][k]+dist[k][j];
    				to[i][j] = to[i][k];
    			}
    		}
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++) printf("%d ",dist[i][j]==INF?0:dist[i][j]);
    	puts("");
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(dist[i][j] == INF){
    			puts("0");
    			continue;
    		}
    		printf("%d",f(i,j));
    		while(!q.empty()){
    			printf(" %d",q.front());
    			q.pop();
    		}
    		puts("");
    	}
    }
}
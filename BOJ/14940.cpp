#include<bits/stdc++.h>
using namespace std;
int n, m, mp[1010][1010], dis[1010][1010], dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
queue<int> qx, qy, qc;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",mp[i]+j);
			dis[i][j] = -1;
			if(mp[i][j] == 2) qx.push(i), qy.push(j), qc.push(0);
			if(mp[i][j] != 1) dis[i][j] = 0;
		}
	}
	while(!qx.empty()){
		int x = qx.front(), y = qy.front(), c = qc.front();
		qx.pop(), qy.pop(), qc.pop();

		for(int i=0;i<4;i++){
			int xx = x + dx[i], yy = y + dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || dis[xx][yy] != -1) continue;
			qx.push(xx), qy.push(yy), qc.push(c+1);
			dis[xx][yy] = c+1;
		}
	}
	for(int i=1;i<=n;i++,puts("")) for(int j=1;j<=m;j++) printf("%d ",dis[i][j]);
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k,dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},mp[111][111],chk[111][111][2];
queue<int> qx,qy,qt,qc;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&mp[i][j]);
	qx.push(1),qy.push(1),qt.push(0),qc.push(0);
	while(!qx.empty()){
		int x = qx.front(), y = qy.front(), t = qt.front(), c = qc.front();
		qx.pop(), qy.pop(), qt.pop(), qc.pop();
		if(x == n && y == m) return !printf("%d",c);
		if(c > k) break;
		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			int tt=t | (mp[xx][yy] == 2);
			if(xx<1 || yy<1 || xx>n || yy>m || (mp[xx][yy] == 1 && !t) || chk[xx][yy][tt]) continue;
			chk[xx][yy][tt] = 1;
			qx.push(xx), qy.push(yy), qt.push(tt), qc.push(c+1);
		}
	}
	printf("Fail");
}
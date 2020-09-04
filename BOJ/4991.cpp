#include<bits/stdc++.h>
using namespace std;
int n, m, chk[30][30][1<<10], T, l[30][30], dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
char mp[30][30];
int main(){
	while(++T){
		scanf("%d %d",&m,&n);
		if(!n && !m) break;
		for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
		queue<int> qx, qy, qt, qc;
		int cnt = 0, fl = 0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == 'o') qx.push(i), qy.push(j), qt.push(0), qc.push(0), chk[i][j][0] = T;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == '*') ++cnt, l[i][j] = 1<<(cnt-1);
		while(!qx.empty()){
			int x = qx.front(), y = qy.front(), t = qt.front(), c = qc.front();
			qx.pop(), qy.pop(), qt.pop(), qc.pop();
			if(t == (1<<cnt)-1){
				printf("%d\n",c);
				fl = 1;
				break;
			}
			for(int i=0;i<4;i++){
				int xx = x+dx[i], yy = y+dy[i], tt = t|(mp[xx][yy]=='*'?l[xx][yy]:0);
				if(xx<1 || yy<1 || xx>n || yy>m || mp[xx][yy] == 'x' || chk[xx][yy][tt] == T) continue;
				chk[xx][yy][tt] = T;
				qx.push(xx), qy.push(yy), qt.push(tt), qc.push(c+1);
			}
		}
		if(!fl) puts("-1");
	}
}
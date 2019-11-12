#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m,chk[1010][1010],chk2[1010][1010],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
char s[1010][1010];
queue<int> qx,qy,qc;
int f(int x,int y){
	int c = 0;
	qx.push(x), qy.push(y), qc.push(1);
	chk2[x][y] = t+1;
	while(!qx.empty()){
		x=qx.front(), y=qy.front(), c=qc.front();
		qx.pop(),qy.pop(),qc.pop();

		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || s[xx][yy] == '#' || chk2[xx][yy] == t+1) continue;
			chk2[xx][yy] = t+1;
			qx.push(xx), qy.push(yy), qc.push(c+1);
		}
	}

	qx.push(x), qy.push(y), qc.push(1);
	chk[x][y] = t+1;
	while(!qx.empty()){
		x=qx.front(), y=qy.front(), c=qc.front();
		qx.pop(),qy.pop(),qc.pop();

		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || s[xx][yy] == '#' || chk[xx][yy] == t+1) continue;
			chk[xx][yy] = t+1;
			qx.push(xx), qy.push(yy), qc.push(c+1);
		}
	}

	return c;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
		int ans=0;
		for(int i=1;i<=n && !ans;i++) for(int j=1;j<=m && !ans;j++) if(s[i][j] == '.') ans = f(i,j);
		printf("Maximum rope length is %d.\n",ans-1);
	}
}
#include<bits/stdc++.h>
using namespace std;
int n,m,mp[303][303],chk[303][303];
queue<int> qx,qy,qc;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&mp[i][j]);
    qx.push(1),qy.push(1),qc.push(0);
	chk[1][1] = 1;
	while(!qx.empty()){
		int x=qx.front(),y=qy.front(),c=qc.front();
		qx.pop(),qy.pop(),qc.pop();

		if(x==n && y==m) return !printf("%d",c);

		for(int i=1;i<=mp[x][y];i++){
			if(x+i>n) break;
			if(chk[x+i][y]) continue;
			chk[x+i][y]=1;
			qx.push(x+i),qy.push(y),qc.push(c+1);
		}
		for(int i=1;i<=mp[x][y];i++){
			if(y+i>m) break;
			if(chk[x][y+i]) continue;
			chk[x][y+i]=1;
			qx.push(x),qy.push(y+i),qc.push(c+1);
		}
	}
}
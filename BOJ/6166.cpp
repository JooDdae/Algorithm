#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk[333][333],mp[333][333],dx[5]={0,0,1,-1,0},dy[5]={1,-1,0,0,0};
queue<int> qx,qy,qc;
int main(){
	for(int i=1;i<=304;i++) for(int j=1;j<=304;j++) mp[i][j] = 1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		a++,b++;
		for(int j=0;j<5;j++){
			int x=a+dx[j], y=b+dy[j];
			mp[x][y] = min(mp[x][y], c);
		}
	}
	if(!mp[1][1]) return !printf("-1");
	qx.push(1),qy.push(1),qc.push(0);
	chk[1][1] = 1;
	while(!qx.empty()){
		int x=qx.front(),y=qy.front(),c=qc.front();
		qx.pop(),qy.pop(),qc.pop();
		if(mp[x][y] > 1000) return !printf("%d",c);

		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			if(chk[xx][yy] || mp[xx][yy] <= c+1) continue;
			qx.push(xx),qy.push(yy),qc.push(c+1);
			chk[xx][yy] = 1;
		}
	}
	printf("-1");
}
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,t,c;
	bool operator < (const node &a)const{
		return c > a.c;
	}
};
int n,m,mp[1010][1010],chk[1010][1010][4],dy[3]={-1,0,1};
priority_queue<node> pq;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&mp[i][j]);
	for(int i=1;i<=m;i++) pq.push({0,i,3,0});
	while(!pq.empty()){
		int x=pq.top().x,y=pq.top().y,t=pq.top().t,c=pq.top().c; pq.pop();
		if(x > n) return !printf("%d",c);
		if(t<3 && chk[x][y][t]) continue;
		chk[x][y][t] = 1;

		for(int i=0;i<3;i++){
			int yy=y+dy[i];
			if(i==t || yy<1 || yy>m || chk[x+1][yy][i]) continue;
			pq.push({x+1,yy,i,c+mp[x+1][yy]});
		}
	}
}
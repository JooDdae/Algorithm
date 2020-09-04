#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int x, y, c;
	bool operator < (const node &a)const{
		return c > a.c;
	}
};
int n,m,ans,chk[55][55],chk2[55][55],fl,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char mp[55][55];
queue<int> qx,qy,qc;
vector<node> v[55][55];
priority_queue<node> pq;
void bfs(int a,int b){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chk2[i][j] = 0;
	qx.push(a), qy.push(b), qc.push(0);
	chk2[a][b] = 1;
	while(!qx.empty()){
		int x = qx.front(), y = qy.front(), c = qc.front();
		qx.pop(), qy.pop(), qc.pop();
		if(c && mp[x][y] != '0') v[a][b].push_back({x, y, c});
		for(int i=0;i<4;i++){
			int xx = x+dx[i], yy = y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>n || mp[xx][yy] == '1' || chk2[xx][yy]) continue;
			chk2[xx][yy] = 1;
			qx.push(xx), qy.push(yy), qc.push(c+1);
		}
	}
	if(fl++ == 0){
		for(auto u : v[a][b]) pq.push({u.x, u.y, u.c});
		chk[a][b] = 1;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp[i][j] != '1' && mp[i][j] != '0') bfs(i, j);
	while(!pq.empty()){
		int x=pq.top().x, y=pq.top().y, c=pq.top().c; pq.pop();
		if(chk[x][y]) continue;
		for(auto u : v[x][y]) pq.push({u.x, u.y, u.c});
		chk[x][y] = 1;
		ans += c;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if((mp[i][j] == 'S' || mp[i][j] == 'K') && !chk[i][j]) return !printf("-1");
	printf("%d",ans);
}
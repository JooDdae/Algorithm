#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int val,x,y;
	bool operator < (const node &a)const{
		return val>a.val;
	}
};
int n,m,mp[333][333],chk[333][333],sz[333][333],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
pair<int,int> par[333][333];
priority_queue<node> pq;
ll ans;
pair<int,int> f(pair<int,int> a){
	if(par[a.first][a.second] == a) return a;
	return par[a.first][a.second] = f(par[a.first][a.second]);
}
ll uni(pair<int,int> a, pair<int,int> b){
	ll re = 1ll * sz[b.first][b.second] * (mp[a.first][a.second] - mp[b.first][b.second]);
	par[b.first][b.second] = {a.first, a.second};
	sz[a.first][a.second] += sz[b.first][b.second];
	chk[a.first][a.second] |= chk[b.first][b.second];
	return re;
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			par[i][j] = {i,j};
			chk[i][j] = (i==1 || i==n || j==1 || j==m);
			sz[i][j] = 1;
			scanf("%d",&mp[i][j]);
			pq.push({mp[i][j],i,j});
		}
	}

	while(!pq.empty()){
		int x=pq.top().x, y=pq.top().y;
		pq.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i], yy=y+dy[i];
			if(xx<1 || yy<1 || xx>n || yy>m || mp[xx][yy] > mp[x][y] || f({xx,yy}) == f({x,y})) continue;
			pair<int,int> p = f({xx, yy});
			ans += uni(f({x,y}), p) * (1 - chk[p.first][p.second]);
		}
	}
	printf("%lld",ans);
}
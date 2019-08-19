#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,cost;
	bool operator < (const node &a)const{
		return cost > a.cost;
	}
};
int n,mp[130][130],chk[130][130],t,ans,dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
int main(){
    while(++t){
    	scanf("%d",&n);
    	if(!n) break;
    	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&mp[i][j]);
    	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chk[i][j] = 0;
		priority_queue<node> pq;
		pq.push({1,1,mp[1][1]});
		while(!pq.empty()){
			int x=pq.top().x,y=pq.top().y;
			ans = pq.top().cost;
			pq.pop();
			if(chk[x][y]) continue;
			chk[x][y] = 1;
			if(x == n && y == n) break;

			for(int i=0;i<4;i++){
				int xx=x+dx[i],yy=y+dy[i];
				if(xx<1 || yy<1 || xx>n || yy>n || chk[xx][yy]) continue;
				pq.push({xx,yy,ans+mp[xx][yy]});
			}
		}
    	printf("Problem %d: %d\n",t,ans);
    }
}
#include<bits/stdc++.h>
using namespace std;
int a,b,c,mp[111][111],t,chk[111],x=3,y=3,mx;
priority_queue<pair<int,int>> pq;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=101;i++) for(int j=1;j<=101;j++) mp[i][j] = -1;
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%d",mp[i]+j);

	while(++t){
		if(mp[a][b] == c) return !printf("%d",t-1);
		if(t > 100) return !printf("-1");

		if(x >= y){
			mx = 0;
			for(int i=1;i<=x;i++){
				for(int j=1;j<=y;j++) chk[mp[i][j]]++;
				for(int k=1;k<=100;k++) if(chk[k]) pq.push({-chk[k],-k}), chk[k]=0;
				mx = min(max(mx, 2*(int)pq.size()), 100);

				int cur = 1;
				while(!pq.empty()){
					if(cur <= mx){
						mp[i][cur++] = -pq.top().second;
						mp[i][cur++] = -pq.top().first;
					}
					pq.pop();
				}
				for(int j=cur;mp[i][j]>=0;j++) mp[i][j] = 0;
			}
			y = max(y,mx);
			for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) if(mp[i][j]<0) mp[i][j] = 0;
		}else{
			mx = 0;
			for(int i=1;i<=y;i++){
				for(int j=1;j<=x;j++) chk[mp[j][i]]++;
				for(int k=1;k<=100;k++) if(chk[k]) pq.push({-chk[k],-k}), chk[k]=0;
				mx = min(max(mx, 2*(int)pq.size()), 100);

				int cur = 1;
				while(!pq.empty()){
					if(cur <= mx){
						mp[cur++][i] = -pq.top().second;
						mp[cur++][i] = -pq.top().first;
					}
					pq.pop();
				}
				for(int j=cur;mp[j][i]>=0;j++) mp[j][i] = 0;
			}
			x = max(x,mx);
			for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) if(mp[i][j]<0) mp[i][j] = 0;
		}
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int to, cnt;
	ll cost;
	bool operator < (const node &o) const{
		return cost > o.cost;
	}
};
int n, m, k;
ll dis[10010][22];
vector<pair<int,int>> v[10010];
priority_queue<node> pq;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) dis[i][j] = 1e18;
	pq.push({1, 0, 0});
	dis[1][0] = 0;
	while(!pq.empty()){
		int cur = pq.top().to, cnt = pq.top().cnt;
		ll cost = pq.top().cost; pq.pop();
		if(dis[cur][cnt] < cost) continue;

		if(cur == n) return !printf("%lld",cost);

		for(auto nxt : v[cur]){
			if(cost + nxt.second < dis[nxt.first][cnt]){
				dis[nxt.first][cnt] = cost + nxt.second;
				pq.push({nxt.first, cnt, cost + nxt.second});
			}
			if(cnt < k && cost < dis[nxt.first][cnt+1]){
				dis[nxt.first][cnt+1] = cost;
				pq.push({nxt.first, cnt+1, cost});
			}
		}
	}
}
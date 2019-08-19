#include<bits/stdc++.h>
using namespace std;
int n,m,s,dist[20202];
vector<pair<int,int>> v[20202];
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=m;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++) dist[i] = 1e9;
	dist[s] = 0;
    pq.push({0,s});
	while(!pq.empty()){
		int cur=pq.top().second, cost=-pq.top().first;
		pq.pop();
		if(dist[cur] < cost) continue;
		for(pair<int,int> nxt : v[cur]){
			if(dist[nxt.first] < cost + nxt.second) continue;
			dist[nxt.first] = cost + nxt.second;
			pq.push({-dist[nxt.first], nxt.first});
		}
	}
	for(int i=1;i<=n;i++){
		if(dist[i] == 1e9) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
}
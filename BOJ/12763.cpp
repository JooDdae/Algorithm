#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,time,cost;
	bool operator < (const node &a)const{
		return cost < a.cost;
	}
};
int n,t,m,q,dis[111][10101],ans=-1;
vector<node> v[111];
priority_queue<node> pq;
int main(){
    scanf("%d %d %d %d",&n,&t,&m,&q);
    for(int i=1;i<=n;i++) for(int j=0;j<=t;j++) dis[i][j]=-1;
    while(q--){
    	int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d);
    	v[a].push_back({b,c,d});
    	v[b].push_back({a,c,d});
    }
    pq.push({1,t,m});
    dis[1][t] = m;
    while(!pq.empty()){
    	int cur=pq.top().to,time=pq.top().time,cost=pq.top().cost;
    	pq.pop();
    	if(dis[cur][time] > cost) continue;

    	for(node nxt : v[cur]){
    		if(time < nxt.time || cost < nxt.cost || dis[nxt.to][time-nxt.time] >= cost-nxt.cost) continue;
    		dis[nxt.to][time-nxt.time] = cost-nxt.cost;
    		pq.push({nxt.to, time-nxt.time, cost-nxt.cost});
    	}
    }
    for(int i=0;i<=t;i++) ans=max(ans,dis[n][i]);
    printf("%d",ans<0?-1:m-ans);
}
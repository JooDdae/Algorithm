// boj.kr/1753
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 20202

struct node{
	int to,cost;
	bool operator < (const node &a)const{
		return cost > a.cost;
	}
};
int n,m,s,dist[MAX_N];
priority_queue<node> pq;
vector<node> v[MAX_N];

int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
	}
	pq.push({s,1});
	while(!pq.empty()){
		int cur=pq.top().to,cost=pq.top().cost;
		pq.pop();
		if(dist[cur]) continue;
		dist[cur] = cost;
		for(node nxt : v[cur]) if(!dist[nxt.to]) pq.push({nxt.to, nxt.cost+cost});
	}
	for(int i=1;i<=n;i++){
		if(dist[i]) printf("%d\n",dist[i]-1);
		else puts("INF");
	}
}
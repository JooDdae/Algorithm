// boj.kr/11657
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 505

struct node{ int to,cost; };
int n,m,dist[MAX_N],chk[MAX_N],vist[MAX_N],INF=1e9;
vector<node> v[MAX_N];
queue<int> q;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
	}
	for(int i=2;i<=n;i++) dist[i] = INF;
	q.push(1);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		chk[cur] = 0;
		for(auto nxt : v[cur]){
			if(dist[nxt.to] > dist[cur] + nxt.cost){
				dist[nxt.to] = dist[cur] + nxt.cost;
				if(vist[nxt.to] == n) return !printf("-1"); 
				if(!chk[nxt.to]) q.push(nxt.to), chk[nxt.to]=1, vist[nxt.to]++;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(dist[i] < INF) printf("%d\n",dist[i]);
		else puts("-1");
	}
}
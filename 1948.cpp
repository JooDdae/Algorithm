#include<bits/stdc++.h>
using namespace std;
int n,m,s,e,p[10101],cost[10101],chk[10101],cnt;
vector<pair<int,int>> v[10101],nv[10101];
queue<int> q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
		nv[b].push_back({a,c});
		p[b]++;
	}
	scanf("%d %d",&s,&e);
	q.push(s);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(pair<int,int> nxt : v[cur]){
			cost[nxt.first] = max(cost[nxt.first], cost[cur]+nxt.second);
			if(--p[nxt.first] == 0) q.push(nxt.first);
		}
	}

	q.push(e);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(pair<int,int> nxt : nv[cur]){
			if(cost[nxt.first] == cost[cur]-nxt.second){
				cnt++;
				if(!chk[nxt.first]){
					chk[nxt.first] = 1;
					q.push(nxt.first);
				}
			}
		}
	}
	printf("%d\n%d",cost[e],cnt);
}
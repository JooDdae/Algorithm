#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,t,chk[111],chk2[111];
vector<int> v[111];
vector<pair<int,int>> ans;
queue<int> q, qc;
priority_queue<int,vector<int>,greater<int>> pq;
int bfs(int u){
	int re = 0;
	q.push(u), qc.push(0);
	chk2[u] = u;
	while(!q.empty()){
		int cur = q.front(), c = qc.front(); q.pop(), qc.pop();
		re = max(re, c);
		for(int x : v[cur]){
			if(chk2[x] != u){
				chk2[x] = u;
				chk[x] = chk[u];
				q.push(x), qc.push(c+1);
			}
		}
	}
	return re;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		if(!chk[i]){
			chk[i] = ans.size() + 1;
			ans.push_back({1e9,0});
		}
		ans[chk[i]-1] = min(ans[chk[i]-1], make_pair(bfs(i), i));
	}

	printf("%d\n",ans.size());
	for(auto x : ans) pq.push(x.second);
	while(!pq.empty()){
		printf("%d\n",pq.top());
		pq.pop();
	}
}
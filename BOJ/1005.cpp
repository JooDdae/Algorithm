#include<bits/stdc++.h>
using namespace std;
int t,n,m,e,cost[1010],p[1010],ans[1010];
vector<int> v[1010];
queue<int> q;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&cost[i]);
		for(int i=1;i<=m;i++){
			int a,b; scanf("%d %d",&a,&b);
			v[a].push_back(b);
			p[b]++;
		}
		scanf("%d",&e);
		for(int i=1;i<=n;i++) if(!p[i]) q.push(i);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			for(int nxt : v[cur]){
				ans[nxt] = max(ans[nxt], ans[cur]+cost[cur]);
				p[nxt]--;
				if(!p[nxt]) q.push(nxt);
			}
		}
		printf("%d\n",ans[e]+cost[e]);
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) p[i]=ans[i]=0;
	}
}
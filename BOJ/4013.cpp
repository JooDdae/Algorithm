#include<bits/stdc++.h>
using namespace std;
int n,m,s,cnt,ans,cost[505050],chk[505050],scc[505050],dp[505050],can[505050];
vector<int> v[505050],nv[505050],scv[505050];
stack<int> st;
void dfs(int cur){
	chk[cur] = 1;
	for(int nxt : nv[cur]) if(!chk[nxt]) dfs(nxt);
	st.push(cur);
}
void dfs2(int cur){
	scc[cur] = cnt;
	for(int nxt : v[cur]) if(!scc[nxt]) dfs2(nxt);
}
void dfs3(int cur){
	chk[cur] = 0;
	for(int nxt : scv[cur]) if(chk[nxt]) dfs3(nxt);
	st.push(cur);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	v[a].push_back(b);
    	nv[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(!chk[i]) dfs(i);
    while(!st.empty()){
    	int cur = st.top();
    	st.pop();
    	if(scc[cur]) continue;
    	++cnt;
    	dfs2(cur);
    }
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	cost[scc[i]]+=a;
    }
    for(int i=1;i<=n;i++) for(int nxt : v[i]) if(scc[i] != scc[nxt]) scv[scc[i]].push_back(scc[nxt]);
    scanf("%d %*d",&s);
    dfs3(scc[s]);
    while(!st.empty()){
    	int cur=st.top();
    	st.pop();
    	can[cur] =1;
    	for(int nxt : scv[cur]) dp[nxt] = max(dp[nxt], dp[cur]+cost[cur]);
    }
	while(~scanf("%d",&s)) if(can[scc[s]]) ans = max(ans, dp[scc[s]]+cost[scc[s]]);
	printf("%d",ans);
}
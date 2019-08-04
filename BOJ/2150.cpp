#include<bits/stdc++.h>
using namespace std;
int n,m,chk[101010];
vector<vector<int>> scc;
vector<int> v[101010],nv[101010],sc;
stack<int> st;
void dfs1(int cur){
	chk[cur] = 1;
	for(int nxt : nv[cur]) if(!chk[nxt]) dfs1(nxt);
	st.push(cur);
}
void dfs2(int cur){
	chk[cur] = 2;
	for(int nxt : v[cur]) if(chk[nxt]!=2) dfs2(nxt);
	sc.push_back(cur);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		nv[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!chk[i]) dfs1(i);
	while(!st.empty()){
		int cur=st.top();
		st.pop();
		if(chk[cur] == 2) continue;
		dfs2(cur);
		sort(sc.begin(),sc.end());
		scc.push_back(sc);
		sc.clear();
	}
	sort(scc.begin(),scc.end());
	printf("%d\n",scc.size());
	for(vector<int> nxt : scc){
		for(int x : nxt) printf("%d ",x);
		puts("-1");
	}
}
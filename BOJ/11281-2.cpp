#include<bits/stdc++.h>
using namespace std;
int n,m,chk[20202],cnt,scc[20202],res[10101];
vector<int> v[20202],nv[20202];
vector<pair<int,int>> p;
stack<int> st;
void dfs(int cur){
	chk[cur] = 1;
	for(int nxt : nv[cur]) if(!chk[nxt]) dfs(nxt);
	st.push(cur);
}
void dfs2(int cur,int t){
	chk[cur] = 2;
	scc[cur] = t;
	for(int nxt : v[cur]) if(chk[nxt] != 2) dfs2(nxt, t);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	a = a<0 ? -(a+1)*2 : a*2-1;
    	b = b<0 ? -(b+1)*2 : b*2-1;
    	v[a^1].push_back(b);
    	v[b^1].push_back(a);
    	nv[b].push_back(a^1);
    	nv[a].push_back(b^1);
    }
    for(int i=0;i<n*2;i++) if(!chk[i]) dfs(i);
    while(!st.empty()){
    	int cur = st.top();
    	st.pop();
    	if(chk[cur] == 2) continue;
    	dfs2(cur, ++cnt);
    }
    for(int i=0;i<n;i++) if(scc[i*2] == scc[i*2+1]) return !printf("0");
    printf("1\n");
	for(int i=1;i<=n;i++) res[i] = -1;
	for(int i=0;i<n*2;i++) p.push_back({scc[i],i});
	sort(p.begin(),p.end());
	for(int i=p.size()-1;i>=0;i--) if(res[p[i].second/2+1] == -1) res[p[i].second/2+1] = !(p[i].second % 2);
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
}
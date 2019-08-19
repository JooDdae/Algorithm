#include<bits/stdc++.h>
using namespace std;
int n,m,chk[2020],scc[2020];
vector<int> v[2020],nv[2020];
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
    while(~scanf("%d %d",&n,&m)){
    	for(int i=1;i<=m;i++){
    		int a,b; scanf("%d %d",&a,&b);
    		a = a<0 ? -(a+1)*2 : a*2-1;
    		b = b<0 ? -(b+1)*2 : b*2-1;
    		v[a^1].push_back(b);
    		v[b^1].push_back(a);
    		nv[a].push_back(b^1);
    		nv[b].push_back(a^1);
    	}
    	v[1].push_back(1);
    	nv[1].push_back(1);
    	for(int i=0;i<n*2;i++) if(!chk[i]) dfs(i);
    	int cnt = 0;
    	while(!st.empty()){
    		int cur=st.top();
    		st.pop();
    		if(chk[cur] == 2) continue;
    		dfs2(cur, ++cnt);
    	}
    	int fl=!(scc[0] > scc[1]);
    	for(int i=0;i<n;i++) if(scc[i*2] == scc[i*2+1]) fl = 1;
    	printf("%s\n",fl?"no":"yes");
    	for(int i=0;i<2*n;i++) chk[i] = 0;
    	for(int i=0;i<2*n;i++) v[i].clear(),nv[i].clear();
    }
}
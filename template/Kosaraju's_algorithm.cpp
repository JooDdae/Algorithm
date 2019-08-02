// boj.kr/2150
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 10101

int n,m,chk[MAX_N];
vector<int> v[MAX_N], nv[MAX_N],sc;
vector<vector<int>> scc;
stack<int> st;

void dfs1(int cur){
	chk[cur] = 1;
	for(int nxt : nv[cur]) if(!chk[nxt]) dfs1(nxt);
	st.push(cur);
}

void dfs2(int cur){
	chk[cur] = 2;
	for(int nxt : v[cur]) if(chk[nxt] != 2) dfs2(nxt);
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
    for(vector<int> s : scc){
    	for(int x : s) printf("%d ",x);
    	puts("-1");
    }
}
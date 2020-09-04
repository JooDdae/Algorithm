#include<bits/stdc++.h>
using namespace std;
int n, m, q, dist[1010], s[100100], e[100100], chk[100100], p[200200], ans[200200];
char c[200200];
vector<int> v[1010];
queue<int> qu, qc;
void bfs(int a, int b){
	qu.push(a), qc.push(b);
	while(!qu.empty()){
		int u = qu.front(), c = qc.front();
		qu.pop(), qc.pop();
		for(int x : v[u]) if(c+1 < dist[x]) dist[x] = c+1, qu.push(x), qc.push(c+1);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=m;i++) scanf("%d %d",s+i,e+i);
	for(int i=1;i<=q;i++) scanf(" %c %d",c+i,p+i);
	for(int i=2;i<=n;i++) dist[i] = 1e9;
	for(int i=1;i<=q;i++) if(c[i] == 'U') chk[p[i]] = 1;
	for(int i=1;i<=m;i++) if(!chk[i]) v[s[i]].push_back(e[i]);
	bfs(1, 0);
	for(int i=q;i>=1;i--){
		if(c[i] == 'U') v[s[p[i]]].push_back(e[p[i]]), bfs(s[p[i]], dist[s[p[i]]]);
		else ans[i] = dist[p[i]]>m?-1:dist[p[i]];
	}
	for(int i=1;i<=q;i++) if(c[i] == 'E') printf("%d\n",ans[i]);
}
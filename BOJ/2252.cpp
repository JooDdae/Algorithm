#include<bits/stdc++.h>
using namespace std;
int n,m,p[32001];
vector<int> v[32001];
queue<int> q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		p[b]++;
	}
	for(int i=1;i<=n;i++) if(!p[i]) q.push(i);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		printf("%d ",cur);
		for(int nxt : v[cur]) if(--p[nxt]==0) q.push(nxt);
	}
}
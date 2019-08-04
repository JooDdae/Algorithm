#include<bits/stdc++.h>
using namespace std;
int n,m,p[32001];
vector<int> v[32001];
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		p[b]++;
	}
	for(int i=1;i<=n;i++) if(!p[i]) pq.push(i);
	while(!pq.empty()){
		int cur=pq.top();
		pq.pop();
		printf("%d ",cur);
		for(int nxt : v[cur]) if(--p[nxt]==0) pq.push(nxt);
	}
}
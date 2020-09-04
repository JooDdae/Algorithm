#include<bits/stdc++.h>
using namespace std;
int n, m, chk[300300], cnt[300300];
double e[300300];
vector<int> v[300300];
priority_queue<pair<double, int>> pq;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a, b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<n;i++) e[i] = v[i].size();
	pq.push({0, n});
	while(!pq.empty()){
		int u = pq.top().second;
		double c = -pq.top().first;
		pq.pop();
		if(chk[u]++) continue;
		e[u] = c;
		for(int x : v[u]) if(!chk[x]) cnt[x]++, e[x] += e[u], pq.push({-e[x]/cnt[x], x});
	}

	printf("%.10f",e[1]);
}
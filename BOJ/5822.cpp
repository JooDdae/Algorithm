#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, p[100100], chk[100100], mn1[100100], mn2[100100];
vector<pair<int, int>> v[100100];
priority_queue<pair<int,int>> pq;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) mn1[i] = 1e9+1, mn2[i] = 1e9+2;
	for(int i=1;i<=m;i++){
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		v[a+1].push_back({b+1, c});
		v[b+1].push_back({a+1, c});
		p[a+1]++, p[b+1]++;
	}
	for(int i=1;i<=k;i++){
		int a; scanf("%d",&a);
		pq.push({0, a+1});
		mn1[a+1] = mn2[a+1] = 0;
	}
	while(!pq.empty()){
		int u = pq.top().second, c = -pq.top().first; pq.pop();
		if(chk[u]++) continue;

		for(auto x : v[u]) if(!chk[x.first]){
			if(mn2[x.first] > x.second + c) mn2[x.first] = x.second + c;
			if(mn1[x.first] > mn2[x.first]) swap(mn1[x.first], mn2[x.first]);

			if(mn2[x.first] < 1e9+1) pq.push({-mn2[x.first], x.first});
		}
	}
	printf("%d\n",mn2[1]);
}
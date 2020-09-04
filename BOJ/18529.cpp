#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, mp[55][55], dist[55][55], mn = INF;
vector<pair<int, int>> v[2555];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",mp[i]+j);
			v[mp[i][j]].emplace_back(i, j);
			dist[i][j] = mp[i][j] == 1 ? 0 : INF;
		}
	}

	for(int u=1;u<m;u++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][j] == u + 1){
					for(auto x : v[u]) dist[i][j] = min(dist[i][j], dist[x.first][x.second] + abs(i-x.first) + abs(j-x.second));
				}
			}
		}
	}

	for(auto x : v[m]) mn = min(mn, dist[x.first][x.second]);
	printf("%d",mn<INF?mn:-1);
}
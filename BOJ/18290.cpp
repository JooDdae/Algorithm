#include<bits/stdc++.h>
using namespace std;
int n, m, k, mp[11][11], reach[111][111], ans=-1e9;
vector<pair<int,int>> v;
vector<int> s;
void f(int c, int val){
	if(s.size() == k){
		ans = max(ans, val);
		return;
	}

	if(c >= v.size()) return;

	f(c+1, val);
	for(auto x : s) if(reach[x][c]) return;

	s.push_back(c);
	f(c+1, val + mp[v[c].first][v[c].second]);
	s.pop_back();
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",mp[i]+j), v.emplace_back(i, j);
	for(int i=0;i<v.size();i++) for(int j=0;j<i;j++) reach[i][j] = reach[j][i] = (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) == 1);
	f(0, 0);
	printf("%d",ans);
}
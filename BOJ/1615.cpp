#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans, c[2020],b[2020];
int n,m;
pair<int,int> p[2000*2000];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++) cin >> p[i].first >> p[i].second;
	sort(p+1, p+1+m);

	int cur = 1;
	for(int i=1;i<=n;i++){
		while(p[cur].first == i){
			ans += b[n] - b[p[cur].second];
			c[p[cur].second]++;
			cur++;
		}
		for(int j=1;j<=n;j++) b[j] = b[j-1]+c[j];
	}

	cout << ans;
}
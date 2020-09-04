#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,a[100100],chk[100100],ans,cnt;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[100100];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&k);
	while(k--){
		int a,b,c; scanf("%d %d %d",&a,&b,&c);
		v[a].push_back({b,c});
	}
	for(int i=1;i<=n;i++) pq.push({-a[i], i});
	while(!pq.empty()){
		int cur = pq.top().second, c = -pq.top().first;
		pq.pop();
		if(chk[cur]) continue;
		chk[cur] = 1;
		ans = max(ans, c);
		if(++cnt == m) break;
		for(auto nxt : v[cur]){
			a[nxt.first] -= nxt.second;
			pq.push({-a[nxt.first], nxt.first});
		}
	}
	printf("%d",ans);
}
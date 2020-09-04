#include<bits/stdc++.h>
using namespace std;
struct node{
	int w, x, d;
	bool operator < (const node &a){
		return x < a.x;
	}
}a[50050];
int n, l, sum, ans;
priority_queue<pair<int,int>> pq;
vector<int> v1,v2;
int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].w,&a[i].x,&a[i].d);
	for(int i=1;i<=n;i++) sum += a[i].w;
	sort(a+1, a+1+n);
	for(int i=1;i<=n;i++) pq.push({a[i].d < 0 ? -a[i].x : -l + a[i].x , a[i].d});
	int L=1, R=n, lt=0, pl=0;
	while(!pq.empty() && (sum > pl*2 || lt == pq.top().first)){
		if(pq.top().second > 0) pl += a[R--].w;
		if(pq.top().second < 0) pl += a[L++].w;
		lt = pq.top().first;
		pq.pop();
	}
	lt = -lt;
	for(int i=1;i<=n;i++) if(a[i].d > 0) v1.push_back(min(a[i].x + lt, l)), v2.push_back(a[i].x);
	sort(v1.begin(), v1.end()), sort(v2.begin(),v2.end());
	for(int i=1;i<=n;i++) if(a[i].d < 0) ans += v1.size();
	for(int i=1;i<=n;i++) if(a[i].d < 0) ans -= upper_bound(v1.begin(), v1.end(), a[i].x - lt - 1) - v1.begin();
	for(int i=1;i<=n;i++) if(a[i].d < 0) ans -= v2.size() - (lower_bound(v2.begin(), v2.end(), a[i].x + 1) - v2.begin());
	printf("%d",ans);
}
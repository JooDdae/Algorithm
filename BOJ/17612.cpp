#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int time,id,num;
	bool operator < (const node &a)const{
		return tie(time, a.id) > tie(a.time, id);
	}
};
int n,m,a[100100],b[100100];
priority_queue<node> pq,pq2;
long long ans,cnt;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++) pq2.push({0,-i,0});
	for(int i=1;i<=n;i++){
		if(pq2.empty()){
			int t = pq.top().time;
			while(!pq.empty() && pq.top().time == t){
				ans += ++cnt * pq.top().num;
				pq2.push({t, -pq.top().id, 0});
				pq.pop();
			}
		}
		pq.push({pq2.top().time + b[i], -pq2.top().id, a[i]});
		pq2.pop();
	}
	while(!pq.empty()){
		ans += ++cnt * pq.top().num;
		pq.pop();
	}
	cout<<ans;
}
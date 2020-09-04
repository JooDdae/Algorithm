#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[2002002];
queue<int> q;
vector<pair<int,int>> ans;
priority_queue<pair<int,int>> pq;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		if(a[i] == 1) q.push(i);
		else pq.push({-a[i], i});
	}
	while(!pq.empty()){
		pair<int,int> p = pq.top(); pq.pop();
		p.first = -p.first;
		while(--p.first){
			if(q.empty()) return !printf("BRAK");
			ans.push_back({q.front(),p.second});
			q.pop();
		}
		q.push(p.second);
	}
	if(q.size() != 2) return !printf("BRAK");
	for(auto p : ans) printf("%d %d\n",p.first,p.second);
	printf("%d ",q.front());
	q.pop();
	printf("%d",q.front());
}
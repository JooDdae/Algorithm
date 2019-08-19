#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,e,chk[1010];
vector<pair<int,int>> v[1010];
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c});
    }
    scanf("%d %d",&s,&e);
    pq.push({0,s});
    while(!pq.empty()){
    	int cur=pq.top().second,cost=-pq.top().first;
    	pq.pop();
    	if(chk[cur]) continue;
    	chk[cur] = 1;
    	if(cur == e) return !printf("%d",cost);
    	for(pair<int,int> nxt : v[cur]) if(!chk[nxt.first]) pq.push({-cost-nxt.second,nxt.first});
    }
}
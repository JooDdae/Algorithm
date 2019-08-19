#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int to,cost,time;
	bool operator < (const node &a)const{
		return time > a.time;
	}
};
int t,n,m,k,c[101][10101];
vector<node> v[101];
priority_queue<node> pq;
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d %d",&n,&m,&k);

    	for(int i=1;i<=n;i++) v[i].clear();
    	for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) c[i][j] = 1e9;

    	for(int i=1;i<=k;i++){
    		int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d);
    		v[a].push_back({b,c,d});
    	}
    	int fl=0;
    	pq.push({1,m,0});
    	while(!pq.empty()){
    		int cur=pq.top().to, cost=pq.top().cost, time=pq.top().time;
    		pq.pop();
    		if(c[cur][cost] < time) continue;

    		if(cur == n){
    			fl=1;
    			printf("%d\n",time);
    			break;
    		}

    		for(node nxt : v[cur])
    			if(cost >= nxt.cost && c[nxt.to][cost-nxt.cost] > time+nxt.time){
    				c[nxt.to][cost-nxt.cost] = time+nxt.time;
    				pq.push({nxt.to,cost-nxt.cost,time+nxt.time});
    			}
    	}

    	if(!fl) printf("Poor KCM\n");
    }
}
#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,cost;
	bool operator < (const node &a)const{
		return cost > a.cost;
	}
};
int n,m,s,e,chk[1010],b[1010];
vector<pair<int,int>> v[1010];
stack<int> st;
priority_queue<node> pq;
int f(int a){
	st.push(a);
	if(a == s) return 1;
	else return f(b[a])+1;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	v[a].push_back({b,c});
    }
    scanf("%d %d",&s,&e);
    pq.push({0,s,0});
    while(!pq.empty()){
    	int cur=pq.top().to,par=pq.top().from,cost=pq.top().cost;
    	pq.pop();
    	if(chk[cur]) continue;
    	chk[cur] = 1;
    	b[cur] = par;
    	if(cur == e){
    		printf("%d\n",cost);
    		break;
    	}
    	for(pair<int,int> nxt : v[cur]) if(!chk[nxt.first]) pq.push({cur,nxt.first,cost+nxt.second});
    }
    printf("%d\n",f(e));
    while(!st.empty()){
    	printf("%d ",st.top());
    	st.pop();
    }
}
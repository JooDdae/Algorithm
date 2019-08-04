// boj.kr/1197
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 10101

struct node{
	int f,s,cost;
	bool operator < (const node &a)const{
		return cost > a.cost;
	}
};
int n,m,ans,par[MAX_N];
priority_queue<node> pq;

int find(int a){
	if(par[a] == a) return a;
	return par[a] = find(par[a]);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=m;i++){
    	int a,b,c; scanf("%d %d %d",&a,&b,&c);
    	pq.push({a,b,c});
    }
    while(!pq.empty()){
    	int a=find(pq.top().f), b=find(pq.top().s), c=pq.top().cost;
    	pq.pop();
    	if(a == b) continue;
    	par[a] = b;
    	ans += c;
    }
    printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int f,s;
	double cost;
	bool operator < (const node &a)const{
		return cost > a.cost;
	}
};
int n,m,par[1010];
ll x[1010],y[1010];
priority_queue<node> pq;
int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}
double ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    for(int i=1;i<=n;i++) scanf("%lld %lld",&x[i],&y[i]);
    for(int i=1;i<=m;i++){
    	int a,b; scanf("%d %d",&a,&b);
    	a=f(a), b=f(b);
    	par[a] = b;
    }
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) pq.push({i,j,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))});
    while(!pq.empty()){
    	int a=f(pq.top().f), b=f(pq.top().s);
    	double c=pq.top().cost;
    	pq.pop();
    	if(a == b) continue;
    	ans += c;
    	par[a] = b;
    }
    printf("%.2f",ans);
}
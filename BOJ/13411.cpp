#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll d,s;
	int id;
	bool operator < (const node &a)const{
		return make_pair(sqrt(d)/s,id) > make_pair(sqrt(a.d)/a.s,a.id);
	}
};
int n;
priority_queue<node> pq;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	ll a,b; int c; scanf("%lld %lld %d",&a,&b,&c);
    	pq.push({a*a+b*b,c,i});
    }
    while(!pq.empty()){
    	printf("%d\n",pq.top().id);
    	pq.pop();
    }
}
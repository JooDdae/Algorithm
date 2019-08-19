#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll x,y;
	node operator - (const node &a)const{
		return {x-a.x, y-a.y};
	}
	bool operator < (const node &a)const{
		return tie(x,y) < tie(a.x,a.y);
	}
};
int n;
vector<node> v;
ll cross(node a,node b){
	return a.x*b.y - a.y*b.x;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	int a,b; char c; scanf("%d %d %c",&a,&b,&c);
    	if(c == 'Y') v.push_back({a,b});
    }
    int it = min_element(v.begin(),v.end()) - v.begin();
    swap(v[it], v[0]);
    sort(v.begin()+1,v.end(),[&](node &a, node &b){
    	ll re = cross(a-v[0], b-v[0]);
    	return re ? re>0 : b<a;
    });
    printf("%d\n",v.size());
    for(node nxt : v) printf("%lld %lld\n",nxt.x,nxt.y);
}
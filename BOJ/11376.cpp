#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cap,val,r;
};
int n,m,chk[2020],ans;
vector<node> v[2020];
int f(int cur,int cap){
	if(cur == 2002) return cap;
	chk[cur] = 1;
	for(auto &e : v[cur]){
		if(chk[e.to] || e.cap == e.val) continue;
		int fl = f(e.to, min(cap, e.cap - e.val));
		if(fl){
			e.val += fl;
			v[e.to][e.r].val -= fl;
			return fl;
		}
	}
	return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	while(a--){
    		int b; scanf("%d",&b);
    		v[i].push_back({n+b,1,0,v[n+b].size()});
    		v[n+b].push_back({i,0,0,v[i].size()-1});
    	}
    }
    for(int i=1;i<=n;i++){
    	v[2001].push_back({i,2,0,v[i].size()});
    	v[i].push_back({2001,0,0,v[2001].size()-1});
    }
    for(int i=n+1;i<=n+m;i++){
    	v[i].push_back({2002,1,0,v[2002].size()});
    	v[2002].push_back({i,0,0,v[i].size()-1});
    }
    while(1){
    	int fl = f(2001,1e9);
    	if(!fl) break;
    	ans += fl;
    	for(int i=1;i<=n+m;i++) chk[i]=0;
    	chk[2001]=0;
    }
    printf("%d",ans);
}
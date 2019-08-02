// boj.kr/6086
#include<bits/stdc++.h>
using namespace std;
#define MAX_N 256
struct node{
	int to,cap,val,r;
};
int n,ans,chk[MAX_N];
vector<node> v[MAX_N];
int f(int cur,int cap){
	if(cur == 'Z') return cap;
	chk[cur] = 1;
	for(node &e : v[cur]){
		if(chk[e.to] || e.val == e.cap) continue;
		int fl = f(e.to, min(cap, e.cap-e.val));
		if(fl){
			e.val += fl;
			v[e.to][e.r].val -= fl;
			return fl;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char a,b; int c; scanf(" %c %c %d",&a,&b,&c);
		v[a].push_back({b,c,0,v[b].size()});
		v[b].push_back({a,0,0,v[a].size()-1});
		v[b].push_back({a,c,0,v[a].size()});
		v[a].push_back({b,0,0,v[b].size()-1});
	}
	while(1){
		int fl = f('A',1e9);
		if(!fl) break;
		ans += fl;
		for(int i='A';i<='z';i++) chk[i]=0;
	}
	printf("%d",ans);
}
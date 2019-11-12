#include<bits/stdc++.h>
using namespace std;
struct node{
	int to, cap, val, rev;
};
int n,m,ans,chk[2020];
char s[111];
map<string,int> mp;
vector<node> v[2020];
void addEdge(int s,int e,int cap){
	v[s].push_back({e, cap, 0, v[e].size()});
	v[e].push_back({s, 0, 0, v[s].size()-1});
}
int f(int cur,int cap){
	if(cur == 2001) return cap;
	chk[cur] = 1;
	for(auto &nxt : v[cur]){
		if(chk[nxt.to] || nxt.cap == nxt.val) continue;
		int fl = f(nxt.to, min(cap, nxt.cap-nxt.val));
		if(fl){
			nxt.val += fl;
			v[nxt.to][nxt.rev].val -= fl;
			return fl;
		}
	}
	return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		mp[s] = i;
		addEdge(n+i, 2001, 1);
	}
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		addEdge(0, i, 1);
		while(a--){
			scanf("%s",s);
			addEdge(i, n+mp[s], 1);
		}
	}
	while(1){
		int fl = f(0, 1e9);
		if(!fl) break;
		ans += fl;
		for(int i=0;i<=2001;i++) chk[i] = 0;
	}
	if(ans == n) printf("YES");
	else printf("NO\n%d",ans);
}
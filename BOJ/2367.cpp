#include<bits/stdc++.h>
using namespace std;
struct node{
	int to, cap, val, rev;
};
int n,m,d,ans,chk[303];
vector<node> v[303];

void addEdge(int l,int r,int fl){
	v[l].push_back({r, fl, 0, v[r].size()});
	v[r].push_back({l, 0, 0, v[l].size()-1});
}

int dfs(int cur,int fl){
	if(cur == 301) return fl;
	chk[cur] = 1;
	for(node &e : v[cur]){
		if(chk[e.to] || e.val == e.cap) continue;
		int f = dfs(e.to, min(fl, e.cap-e.val));
		if(f){
			e.val += f;
			v[e.to][e.rev].val -= f;
			return f;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=d;i++){
		int a; scanf("%d",&a);
		addEdge(0, i, a);
	}

	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		while(a--){
			int b; scanf("%d",&b);
			addEdge(b, d+i, 1);
		}
		addEdge(d+i, 301, m);
	}

	while(1){
		int fl = dfs(0, 1e9);
		if(!fl) break;
		ans += fl;
		for(int i=0;i<=301;i++) chk[i] = 0;
	}
	printf("%d",ans);
}
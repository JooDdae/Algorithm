#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int su, st, ed;
	bool operator < (const node &a)const{
		return make_pair(su, a.ed-a.st) < make_pair(a.su, ed-st);
	}
	node(int a, int b, int c){
		su = a;
		st = b;
		ed = c;
	}
	node(){
		su = st = ed = 0;
	}
}dp[1010];
int n, m, ans;
vector<node> v;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=1;j<=m;j++){
			int a; scanf("%d",&a);
			dp[j] = max(node(dp[j-1].su+a, dp[j-1].st, j), node(a, j, j));
		}
		node mx = dp[1];
		for(int j=2;j<=m;j++) mx = max(mx, dp[j]);
		v.push_back(mx);
		ans += mx.su;
	}
	printf("%d\n",ans);
	for(auto u : v) printf("%d %d\n",u.st,u.ed);
}
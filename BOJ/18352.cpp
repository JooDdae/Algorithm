#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, x, chk[300300];
vector<int> v[300300], ans;
queue<int> qu, qc;
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&x);
	while(m--){
		int a, b; scanf("%d %d",&a,&b);
		v[a].push_back(b);
	}
	qu.push(x), qc.push(0);
	chk[x] = 1;
	while(!qu.empty()){
		int u = qu.front(), c = qc.front(); qu.pop(), qc.pop();
		if(c == k) ans.push_back(u);
		if(c > k) break;
		for(int nxt : v[u]) if(!chk[nxt]) qu.push(nxt), qc.push(c+1), chk[nxt] = 1;
	}
	sort(ans.begin(), ans.end());
	if(ans.empty()) printf("-1");
	else for(int o : ans) printf("%d\n",o);
}
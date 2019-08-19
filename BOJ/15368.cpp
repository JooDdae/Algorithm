#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cnt[202020];
vector<int> v[202020];
pair<ll,int> dfs(int cur){
	cnt[cur] = 1;
	ll re=1;
	int cn=1;
	for(int nxt : v[cur]){
		pair<ll,int> x = dfs(nxt);
		cnt[cur] += x.first+x.second;
		re += x.first+x.second;
		cn += x.second;
	}
	return {re,cn};
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
    	int a; scanf("%d",&a);
    	v[a].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) printf("%lld ",cnt[i]);
}
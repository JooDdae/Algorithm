#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t[10101], p[10101], ans, d[10101];
vector<int> v[10101];
queue<int> qu, qc;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",t+i,p+i);
		for(int j=1;j<=p[i];j++){
			int a; scanf("%d",&a);
			v[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) if(!p[i]) qu.push(i), qc.push(0);
	while(!qu.empty()){
		int u = qu.front(), c = qc.front()+t[u]; qu.pop(), qc.pop();
		ans = max(ans, c);
		for(int x : v[u]){
			d[x] = max(d[x], c);
			if(--p[x] == 0) qu.push(x), qc.push(d[x]);
		}
	}
	printf("%d",ans);
}
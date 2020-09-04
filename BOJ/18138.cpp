#include<bits/stdc++.h>
using namespace std;
int n, m, a[202], b[202], ans, chk[202], match[202];
vector<int> v[202];

int flow(int u){
	chk[u] = 1;
	for(int e : v[u]){
		if(!match[e] || (!chk[match[e]] && flow(match[e]))){
			match[e] = u;
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if((a[i]/2+(a[i]%2?1:0) <= b[j] && b[j] <= a[i]*3/4) || (a[i] <= b[j] && b[j] <= a[i]*5/4)) v[i].push_back(j);
	for(int i=1;i<=n;i++){
		ans += flow(i);
		for(int j=1;j<=n;j++) chk[j] = 0;
	}
	printf("%d",ans);
}
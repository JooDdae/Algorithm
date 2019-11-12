//boj.kr/2188
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 202
#define MAX_M 202

int n, m, ans, chk[MAX_N], match[MAX_M];
vector<int> v[MAX_N];

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
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		while(a--){
			int b; scanf("%d",&b);
			v[i].push_back(b);
		}
	}
	for(int i=1;i<=n;i++){
		ans += flow(i);
		for(int j=1;j<=n;j++) chk[j] = 0;
	}
	printf("%d",ans);
}
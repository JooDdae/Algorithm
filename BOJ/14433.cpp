#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, A, B, chk[1010], match[1010];
vector<int> v[1010];

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
	scanf("%d %d %d %d",&n,&m,&a,&b);
	for(int i=1;i<=a;i++){
		int c,d; scanf("%d %d",&c,&d);
		v[c].push_back(d);
	}
	for(int i=1;i<=b;i++){
		int c,d; scanf("%d %d",&c,&d);
		v[c+n].push_back(d+m);
	}
	for(int i=1;i<=n;i++){
		A += flow(i);
		for(int j=1;j<=n;j++) chk[j] = 0;
	}
	for(int i=1;i<=n;i++){
		B += flow(i+n);
		for(int j=1;j<=n;j++) chk[j+n] = 0;
	}

	puts(A>=B?"그만 알아보자":"네 다음 힐딱이");
}
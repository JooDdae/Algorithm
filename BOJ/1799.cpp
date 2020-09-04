#include<bits/stdc++.h>
using namespace std;
int n, ans, chk[111], match[111];
vector<int> v[111];

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
	scanf("%d",&n);
	int l = n, r = 1;
	for(int i=0;i<n;i++,l-=n+1,r-=n-1){
		for(int j=0;j<n;j++,l++,r++){
			int a; scanf("%d",&a);
			if(!a) continue;

			v[l].push_back(r);
		}
	}

	for(int i=1;i<=4*n;i++){
		ans += flow(i);
		for(int j=1;j<=4*n;j++) chk[j] = 0;
	}
	printf("%d",ans);
}
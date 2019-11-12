#include<bits/stdc++.h>
using namespace std;
int t,n,m,match[101],chk[101];
vector<int> v[101];
int dfs(int cur){
	chk[cur] = 1;
	for(int nxt : v[cur]){
		if(!match[nxt] || (!chk[match[nxt]] && dfs(match[nxt]))){
			match[nxt] = cur;
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;i++){
			int a,b,c; scanf("%d %d %d",&a,&b,&c);
			while(c--){
				int d; scanf("%d",&d);
				for(int j=a+1;j<=b;j++) v[j].push_back(d);
			}
		}

		int ans = 0;
		for(int i=1;i<=100;i++){
			ans += dfs(i);
			if(ans == n){
				printf("%d\n",i);
				break;
			}
			for(int j=1;j<=100;j++) chk[j] = 0;
		}
		if(ans != n) puts("-1");

		for(int i=1;i<=100;i++) v[i].clear();
		for(int i=1;i<=n;i++) match[i] = 0;
	}
}
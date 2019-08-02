#include<bits/stdc++.h>
using namespace std;
int t,n,m,pl[505],p[505],out[505],mp[505][505];
int main(){
	scanf("%d",&t);
	while(t--){
		queue<int> q;
		int cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=0;
		for(int i=1;i<=n;i++) p[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&pl[i]);
			for(int j=1;j<i;j++) mp[pl[j]][pl[i]]=1;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			int a,b; scanf("%d %d",&a,&b);
			mp[a][b]=mp[b][a];
			mp[b][a]=!mp[b][a];
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) p[j]+=mp[i][j];

		for(int i=1;i<=n;i++) if(!p[i]) q.push(i);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			if(!q.empty()) break;
			out[++cnt] = cur;
			for(int i=1;i<=n;i++) if(mp[cur][i]) if(--p[i] == 0) q.push(i);
		}

		if(cnt == n) for(int i=1;i<=n;i++) printf("%d ",out[i]);
		else printf("%s",q.empty()?"IMPOSSIBLE":"?");
		puts("");
	}
}
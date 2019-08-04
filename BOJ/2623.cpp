#include<bits/stdc++.h>
using namespace std;
int n,m,p[1010],cnt,lg[1010];
vector<int> v[1010];
queue<int> q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,l; scanf("%d %d",&a,&l);
		for(int j=1;j<a;j++){
			int b; scanf("%d",&b);
			v[l].push_back(b);
			p[b]++;
			l=b;
		}
	}
	for(int i=1;i<=n;i++) if(!p[i]) q.push(i);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		lg[++cnt] = cur;
		for(int nxt : v[cur]) if(--p[nxt] == 0) q.push(nxt);
	}
	if(cnt < n) printf("0");
	else for(int i=1;i<=n;i++) printf("%d\n",lg[i]);
}
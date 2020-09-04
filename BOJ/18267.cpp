#include<bits/stdc++.h>
using namespace std;
int n, m, num[100100];
char s[100100];
vector<int> v[100100];
void dfs(int cur, int col){
	num[cur] = col;
	for(auto nxt : v[cur]) if(s[cur] == s[nxt] && !num[nxt]) dfs(nxt, col);
}
int main(){
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d %d",&a,&b);
		v[a].push_back(b), v[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!num[i]) dfs(i, i);
	for(int i=1;i<=m;i++){
		int a,b; char c; scanf("%d %d %c",&a,&b,&c);
		printf("%d",s[a]==c||num[a]!=num[b]);
	}
}
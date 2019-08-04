#include<bits/stdc++.h>
using namespace std;
int n,c;
map<string,int> trie[15001];
char s[20];
void dfs(int cur,int lev){
	for(auto it=trie[cur].begin();it!=trie[cur].end();it++){
		for(int i=1;i<=lev;i++) printf("--");
		printf("%s\n",it->first.data());
		dfs(it->second, lev+1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		int cur = 0;
		while(a--){
			scanf(" %s",s);
			if(!trie[cur][s]) trie[cur][s] = ++c;
			cur = trie[cur][s];
		}
	}
	dfs(0,0);
}
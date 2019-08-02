// boj.kr/5052
#include<bits/stdc++.h>
using namespace std;

#define MAX_N 10101
#define MAX_S 10

int t,n,chk[MAX_N*MAX_S];
char s[MAX_S+1];
map<char,int> trie[MAX_N*MAX_S];

int main(){
	scanf("%d",&t);
	while(t--){
		int fl=0,cnt=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			int cur=0;
			for(int j=0;s[j];j++){
				if(!trie[cur][s[j]]) trie[cur][s[j]] = ++cnt;
				cur = trie[cur][s[j]];
				if(chk[cur]) fl=1;
			}
			if(trie[cur].size()) fl=1;
			chk[cur] = 1;
		}
		printf("%s\n",fl?"NO":"YES");
		for(int i=0;i<=cnt;i++) chk[i]=0,trie[i].clear();
	}
}
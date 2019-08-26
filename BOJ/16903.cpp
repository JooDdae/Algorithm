#include<bits/stdc++.h>
using namespace std;
int q,cnt,chk[5800001];
map<int,int> trie[5800001];
int f(int a){
	int re = 0,cur = 0;
	for(int i=29;i>=0;i--){
		if(!trie[cur].count(0) || !chk[trie[cur][0]]) cur = trie[cur][1], re += (a&(1<<i))?0:1<<i;
		else if(!trie[cur].count(1) || !chk[trie[cur][1]]) cur = trie[cur][0], re += (a&(1<<i))?1<<i:0;
		else{
			if(a & (1<<i)) cur = trie[cur][0];
			else cur = trie[cur][1];
			re += 1<<i;
		}
	}
	return re;
}
int main(){
    scanf("%d",&q);

	int cur=0;
	for(int i=29;i>=0;i--){
		cur = trie[cur][0] = ++cnt;
		chk[cur] ++;
	}

    while(q--){
    	int a,b; scanf("%d %d",&a,&b);
    	if(a == 3) printf("%d\n",f(b));
    	else{
			int cur=0;
			for(int i=29;i>=0;i--){
				int fl = !(!(b&(1<<i)));
				if(!trie[cur][fl]) trie[cur][fl] = ++cnt;
				cur = trie[cur][fl];
				chk[cur] += a==1?1:-1;
			}
    	}
    }
}
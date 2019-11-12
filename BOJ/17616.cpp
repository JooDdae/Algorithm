#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,s,chk[100100];
vector<int> up[100100],down[100100];
int U(int cur){
	if(chk[cur] == 1) return 0;
	chk[cur] = 1;
	int re = 1;
	for(int nxt : up[cur]) re += U(nxt);
	return re;
}
int D(int cur){
	if(chk[cur] == 2) return 0;
	chk[cur] = 2;
	int re = 1;
	for(int nxt : down[cur]) re += D(nxt);
	return re;
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		up[b].push_back(a);
		down[a].push_back(b);
	}
	printf("%d %d",U(s),n-D(s)+1);
}
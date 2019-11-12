#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt,chk[111];
vector<int> w[111],l[111];
int W(int a){
	chk[a] = 1;
	int re = 0;
	for(int i : w[a]) if(!chk[i]) re += W(i)+1;
	return re;
}
int L(int a){
	chk[a] = 1;
	int re = 0;
	for(int i : l[a]) if(!chk[i]) re += L(i)+1;
	return re;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b; scanf("%d %d",&a,&b);
		w[a].push_back(b);
		l[b].push_back(a);
	}
	for(int i=1;i<=n;i++) {
		if(W(i) + L(i) == n-1) cnt++;
		for(int j=1;j<=n;j++) chk[j] = 0;
	}
	printf("%d",cnt);
}
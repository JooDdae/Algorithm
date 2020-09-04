#include<bits/stdc++.h>
using namespace std;
int n, chk[55], ans;
char s[55][55];
queue<int> qx, qc;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		int re = 0;
		qx.push(i), qc.push(0);
		chk[i] = 1;
		while(!qx.empty()){
			int x = qx.front(), c = qc.front(); qx.pop(), qc.pop();
			re++;
			if(c <= 1) for(int j=1;j<=n;j++) if(s[x][j] == 'Y' && !chk[j]) qx.push(j), qc.push(c+1), chk[j] = 1;
		}
		ans = max(ans, re-1);
		for(int j=1;j<=n;j++) chk[j] = 0;
	}
	printf("%d",ans);
}
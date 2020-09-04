#include<bits/stdc++.h>
using namespace std;
int n, m, chk[1001001], ans;
char s[1001001];
int main(){
	scanf("%d %d %s",&n,&m,s+1);

	for(int i=3;i<=m;i++){
		if(s[i-2] == 'I' && s[i-1] == 'O' && s[i] == 'I'){
			chk[i] = chk[i-2] + 1;
			if(chk[i] >= n) ans++;
		}
	}

	printf("%d",ans);
}
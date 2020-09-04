#include<bits/stdc++.h>
using namespace std;
int n, m, sz[20][20],ans,b[20];
char mp[20][20];
int f(int a){
	int re = 0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == '#'){
		int k = 1;
		while(mp[i-k][j]=='#' && mp[i+k][j]=='#' && mp[i][j-k]=='#' && mp[i][j+k]=='#') k++;
		re = max(re, k);
	}
	return b[re] * b[a];
}
int main(){
	b[1] = 1;
	for(int i=2;i<=15;i++) b[i] = b[i-1] + 4;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);

	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(mp[i][j] == '#'){
		int k = 0;
		while(mp[i-k][j]=='#' && mp[i+k][j]=='#' && mp[i][j-k]=='#' && mp[i][j+k]=='#'){
			mp[i-k][j]=mp[i+k][j]=mp[i][j-k]=mp[i][j+k]='.';
			ans = max(ans, f(k+1));
			k++;
		}
		for(int l=0;l<k;l++) mp[i-l][j]=mp[i+l][j]=mp[i][j-l]=mp[i][j+l]='#';
	}
	printf("%d",ans);
}
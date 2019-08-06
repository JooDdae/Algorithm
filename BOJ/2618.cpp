#include<bits/stdc++.h>
using namespace std;
int n,m,x[1010],y[1010],dp[1010][1010];
pair<int,int> bt[1010][1010];
int dist(int a,int b,int t){
	if(!a) x[a]=y[a]=t?1:n;
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int f(int a,int b,int cnt){
	if(cnt++ == m) return 0;
	if(dp[a][b] != -1) return dp[a][b];

	int f1 = f(cnt, b, cnt) + dist(a,cnt,0);
	int f2 = f(a, cnt, cnt) + dist(b,cnt,1);

	if(f1 < f2) bt[a][b] = {cnt, b};
	else bt[a][b] = {a, cnt};

	return dp[a][b] = min(f1,f2);
}
void back(int a,int b){
	if(max(a,b) == m) return;
	printf("%d\n",1+(bt[a][b].first!=a));
	back(bt[a][b].first,bt[a][b].second);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d %d",&x[i],&y[i]);
    for(int i=0;i<=m;i++) for(int j=0;j<=m;j++) dp[i][j] = -1;
    printf("%d\n",f(0,0,0));
	back(0,0);
}
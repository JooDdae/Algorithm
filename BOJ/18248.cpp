#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a[1010][101];
pair<int,int> p[1010];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) p[i].first += a[i][j];
	for(int i=1;i<=n;i++) p[i].second = i;
	sort(p+1, p+1+n, greater<>());
	
	for(int i=2;i<=n;i++) for(int j=1;j<=m;j++) if(!a[p[i-1].second][j] && a[p[i].second][j]) return !printf("NO");
	printf("YES");
}
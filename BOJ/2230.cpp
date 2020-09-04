#include<bits/stdc++.h>
using namespace std;
int n, m, a[100100], ans = 2e9;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1, a+1+n);
	for(int i=1,j=1;i<=n;i++){
		while(j<=n && a[j]-a[i] < m) j++;
		if(j > n) break;
		ans = min(ans, a[j] - a[i]);
	}
	printf("%d",ans);
}
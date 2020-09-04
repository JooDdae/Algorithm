#include<bits/stdc++.h>
using namespace std;
int t, n, a[55];
int main(){
	while(++t){
		scanf("%d",&n);
		if(!n) break;
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		int s = 0;
		for(int i=1;i<=n;i++) s += a[i];
		s /= n;
		int ans = 0;
		for(int i=1;i<=n;i++) if(a[i] > s) ans += a[i] - s;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",t,ans);
	}
}
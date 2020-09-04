#include<bits/stdc++.h>
using namespace std;
int n, ans, chk[1010];
int main(){
	chk[1] = 1;
	for(int i=2;i<=1000;i++){
		if(chk[i]) continue;
		for(int j=i+i;j<=1000;j+=i) chk[j] = 1;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		ans += !chk[a];
	}
	printf("%d",ans);
}
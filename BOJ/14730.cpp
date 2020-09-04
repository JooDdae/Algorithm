#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b; scanf("%d %d",&a,&b);
		ans += a * b;
	}
	printf("%d",ans);
}
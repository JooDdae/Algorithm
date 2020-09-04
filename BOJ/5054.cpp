#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a[30];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);

		printf("%d\n",2 * (*max_element(a+1, a+1+n) - *min_element(a+1, a+1+n)));
	}
}
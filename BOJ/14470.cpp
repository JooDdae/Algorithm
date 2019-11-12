#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5],ans;
int main(){
	for(int i=0;i<5;i++) scanf("%d",&a[i]);

	if(a[0] < 0) ans+=-a[0]*a[2]+a[3],a[0]=0;
	printf("%d",ans + (a[1]-a[0])*a[4]);
}
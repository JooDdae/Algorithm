#include<bits/stdc++.h>
using namespace std;
int a[111],n,ans;
int main(){
	while(~scanf("%01d",&a[++n]));
	n--;

	for(int i=1;i<=n;i++) a[i] += a[i-1];
	for(int i=n/2;i>=1;i--){
		for(int j=1;j<=n-i*2+1;j++) if(a[j+i-1] - a[j-1] == a[i+i+j-1] - a[j+i-1]) return !printf("%d",i*2);
	}
	printf("0");
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[101010],b;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	scanf("%lld",&b);

	for(int i=1;i<=n;i++) if(a[i] == b*i || (b*i-b<a[i-1] && a[i]<b*i) || (a[i-1]<b*i-b && b*i<a[i])) return !printf("T");
	printf("F");
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double j,m,a[111];
int main(){
	scanf("%d",&n);
	if(!n) return !printf("divide by zero");
	for(int i=1;i<=n;i++) scanf("%lf",a+i);
	for(int i=1;i<=n;i++) j += a[i];
	for(int i=1;i<=n;i++) m += a[i] / n;

	printf("%.2f",j/m/n);
}
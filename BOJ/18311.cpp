#include<bits/stdc++.h>
using namespace std;
long long m;
int n, a[100100];
int main(){
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		m -= a[i];
		if(m < 0) return !printf("%d",i);
	}
	for(int i=n;i>=1;i--){
		m -= a[i];
		if(m < 0) return !printf("%d",i);
	}
}
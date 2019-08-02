#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll f(ll a){
	a/=2;
	return a*(a+1)/2;
}
int main(){
	scanf("%lld %lld",&a,&b);
	printf("%lld",(f(b)-f(a-1))*2 - (a<=2 && 2<=b)*2);
}
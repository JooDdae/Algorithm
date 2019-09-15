#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll f(ll a,ll s){
	ll cur=s,re=0;
	while(cur <= a){
		re += a/cur;
		cur*=s;
	}
	return re;
}
int main(){
    scanf("%d %d",&n,&m);
    printf("%lld",min(f(n,2)-f(m,2)-f(n-m,2),f(n,5)-f(m,5)-f(n-m,5)));
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[8];
int ccw(ll a,ll b,ll c,ll d,ll e,ll f){
	c-=a, e-=a;
	d-=b, f-=b;
	ll cross = c*f - d*e;
	if(cross > 0) return 1;
	if(cross < 0) return -1;
	return 0;
}
int main(){
	for(int i=0;i<8;i++) scanf("%lld",&a[i]);
	int A = ccw(a[0],a[1],a[2],a[3],a[4],a[5]) * ccw(a[0],a[1],a[2],a[3],a[6],a[7]);
	int B = ccw(a[4],a[5],a[6],a[7],a[0],a[1]) * ccw(a[4],a[5],a[6],a[7],a[2],a[3]);
	else printf("%d",A<=0 && B<=0);
}
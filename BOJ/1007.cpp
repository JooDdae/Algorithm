#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
ll x[22], y[22];
double f(int cur, int cnt, ll xs, ll ys){
	if(cnt == n/2) return sqrt(xs*xs + ys*ys);

	double re = 1e18;
	for(int i=cur;i<=n;i++) re = min(re, f(i+1, cnt+1, xs-x[i]*2, ys-y[i]*2));
	return re;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld %lld",x+i,y+i);
		ll xs = 0, ys = 0;
		for(int i=1;i<=n;i++) xs += x[i], ys += y[i];
		printf("%.10f\n",f(1, 0, xs, ys));
	}
}
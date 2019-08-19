// boj.kr/9240 로버트 후드 / 구현 실수
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
	ll x,y;
	bool operator < (const point &a)const{
		return tie(x,y) < tie(a.x,a.y);
	}
	point operator - (const point &a)const{
		return {x-a.x,y-a.y};
	}
}in[101010],st[101010];
int n,k;
double ans;
ll cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&in[i].x,&in[i].y);
	int it = min_element(in+1,in+1+n) - in;
	swap(in[it], in[1]);
	sort(in+2, in+1+n, [&](point &a, point &b){
		ll fl = cross(a,b);
		return fl?fl>0 : a<b;
	});
	for(int i=1;i<=n;i++){
		while(k>=2 && cross(st[k]-st[k-1],in[i]-st[k-1]) <= 0) k--;
		st[++k] = in[i];
	}
	int r = 2;
	for(int i=1;i<=k;i++){
		while(cross(st[i%k+1]-st[i],st[r%k+1]-st[r]) > 0) r++;
		ans = max(ans, dist(st[i], st[r]));
	}
	printf("%.10f",ans);
}
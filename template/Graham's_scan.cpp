// boj.kr/1708
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX_N 101010

struct point{
	ll x,y;
	bool operator < (const point &a)const{
		return tie(x,y) < tie(a.x,a.y);
	}
	point operator - (const point &a)const{
		return {x-a.x,y-a.y};
	}
}in[MAX_N],st[MAX_N];
int n,k;

ll cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&in[i].x,&in[i].y);
	int it = min_element(in+1,in+1+n) - in;
	swap(in[1], in[it]);
	sort(in+2,in+1+n,[&](point &a,point &b){
		ll re = cross(a-in[1], b-in[1]);
		return re?re>0:a<b;
	});
	for(int i=1;i<=n;i++){
		while(k>=2 && cross(st[k]-st[k-1],in[i]-st[k-1])<=0) k--;
		st[++k] = in[i];
	}
	printf("%d",k);
}
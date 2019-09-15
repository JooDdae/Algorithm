#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y,id;
	bool operator < (const point &a)const{
		return tie(x,y) < tie(a.x,a.y);
	}
	point operator - (const point &a)const{
		return {x-a.x,y-a.y};
	}
}in[2020];
int t,n;
int cross(point a,point b){
	return a.x*b.y - a.y*b.x;
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++) scanf("%d %d",&in[i].x,&in[i].y);
    	for(int i=1;i<=n;i++) in[i].id = i-1;
    	swap(in[1], *min_element(in+1, in+1+n));
    	sort(in+2, in+1+n, [&](point &a,point &b){
    		int re = cross(a-in[1],b-in[1]);
    		return re ? re>0 : a<b;
    	});
    	for(int i=n;i>=2;i--){
    		if(cross(in[i]-in[1], in[i-1]-in[1])){
    			reverse(in+i,in+1+n);
    			break;
    		}
    	}
    	for(int i=1;i<=n;i++) printf("%d ",in[i].id);
    	puts("");
    }
}
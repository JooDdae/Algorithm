#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,e,f;
int F(int A){
	return min(a+A*c, b-A*d);
}
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    	b = a/c*d + b/e*f;
    	a %= c;
    	int l=0,r=b/d+1;
    	while(l<r){
    		int mid = (l+r)/2;
    		if(F(mid) > F(mid+1)) r = mid;
    		else l = mid+1;
    	}
    	printf("%d\n",max({F(l-1),F(l),F(l+1)}));
    }
}
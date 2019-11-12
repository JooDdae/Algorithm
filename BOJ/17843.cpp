#include<bits/stdc++.h>
using namespace std;
int t;
double a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lf %lf %lf",&a,&b,&c);
		a = 1e0*360/12*a + 1e0*360/12/60*b + 1e0*360/12/60/60*c;
		b = 1e0*360/60*b + 1e0*360/60/60*c;
		c = 1e0*360/60*c;
		printf("%.10f\n",min({abs(a-b),abs(b-c),abs(a-c),abs(360-a+c),abs(360-a+b),abs(360-b+a),abs(360-b+c),abs(360-c+a),abs(360-c+b)}));
	}
}
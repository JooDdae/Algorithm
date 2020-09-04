#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
	scanf("%d %d %d %d",&a,&b,&c,&d);
	a *= d, b *= d;
	c *= b/d, d = b;
	a += c;
	printf("%d %d",a/__gcd(a,b),b/__gcd(a,b));
}
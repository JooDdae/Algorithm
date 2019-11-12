#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	d = b*b-4*a*c;
	e = (int)(sqrt(d) + 1e-6);
	a *= 2;
	if(d < 0 || d != e*e || (-b+e)%a || (-b-e)%a || e == 0) return !printf("둘다틀렸근");

	if(__builtin_popcount((-b+e)/a) > 1 || __builtin_popcount((-b-e)/a) > 1 || (-b+e)/a == 1 || (-b-e)/a == 1) return !printf("정수근");

	printf("이수근");
}
#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,a[20],fl;
int f(int x, int y, int z){
	if(!x || !y || !z || fl) return 0;
	int bit = 31 - __builtin_clz(min({x, y, z}));

	while(bit > -1 && !a[bit]) bit--;
	if(bit < 0){
		fl = 1;
		return 0;
	}
	a[bit]--;
	bit = 1<<bit;
	int X = x-bit, Y = y-bit, Z = z-bit;
	return 1 + f(X, bit, bit) + f(bit, Y, bit) + f(bit, bit, Z) + f(X, Y, bit) + f(X, bit, Z) + f(bit, Y, Z) + f(X, Y, Z);
}
int main(){
	scanf("%d %d %d %d",&n,&m,&k,&l);
	while(l--){
		int b; scanf("%d",&b);
		scanf("%d",a+b);
	}
	l = f(n,m,k);
	printf("%d",fl?-1:l);
}
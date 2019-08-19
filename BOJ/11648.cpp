#include<bits/stdc++.h>
using namespace std;
int n;
int f(int a){
	if(a<10) return 0;
	int b = 1;
	while(a){
		b*=a%10;
		a/=10;
	}
	return f(b)+1;
}
int main(){
	scanf("%d",&n);
	printf("%d",f(n));
}
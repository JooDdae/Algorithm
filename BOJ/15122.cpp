#include<cstdio>
int n;
bool f(int a){
	while(a){
		if(a%10 == 0) return false;
		a/=10;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	while(++n) if(f(n)) return !printf("%d",n);
}
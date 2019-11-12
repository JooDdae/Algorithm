#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void f(int a,int b){
	if(a == 0) return;
	f(a/10,b%3+1);
	if(b == 3 && a>9) printf(",");
	printf("%d",a%10);
}
int main(){
	scanf("%d",&n);
	f(n,1);
}
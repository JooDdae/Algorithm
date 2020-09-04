#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
int main(){
	scanf("%d %d %d",&a,&b,&c); a++, b++, c++;
	printf("%d",a*b/c-1);
}
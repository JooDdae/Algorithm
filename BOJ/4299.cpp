#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b;
int main(){
	scanf("%d %d",&a,&b);
	for(int i=0;i<=1000;i++) for(int j=0;j<=i && j+i<=1000;j++) if(i+j == a && i-j == b) return !printf("%d %d",i,j);
	printf("-1");
}
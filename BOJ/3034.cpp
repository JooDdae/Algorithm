#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int main(){
    scanf("%d %d %d",&n,&a,&b);
    while(n--){
    	int c; scanf("%d",&c);
    	printf("%s\n",a*a+b*b>=c*c?"DA":"NE");
    }
}
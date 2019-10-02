#include<bits/stdc++.h>
using namespace std;
long long a,b,c=1;
int main(){
    scanf("%lld %lld",&a,&b);
    for(int i=1;i<=a;i++) c=(c*i)%b;
    printf("%lld",c);
}
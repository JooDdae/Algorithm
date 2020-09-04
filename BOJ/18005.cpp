#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main(){
    scanf("%lld",&n);
    ll f1=n*(n+1)/2, f2=(n+1)*(n+2)/2-1;
    
    if(f1%2 && f2%2) printf("1");
    else if(f1%2==0 && f2%2==0) printf("2");
    else printf("0");
}
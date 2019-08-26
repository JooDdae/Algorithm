#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,b;
int main(){
    scanf("%lld %lld %lld",&n,&a,&b);
    printf("%lld %lld",(1ll<<a)-1 + n-a,(1ll<<b)-1 + (1ll<<b-1)*(n-b));
}
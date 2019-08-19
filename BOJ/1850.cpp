#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main(){
    scanf("%lld %lld",&a,&b);
    for(int i=__gcd(a,b);i>=1;i--) printf("1");
}
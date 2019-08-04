#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        ll a,b,c; scanf("%lld %lld %lld",&a,&b,&c);
        printf("%lld\n",min({(a+b)*(a+b)+c*c,(c+b)*(c+b)+a*a,(a+c)*(a+c)+b*b}));
    }
}

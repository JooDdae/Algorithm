#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;
int main(){
    scanf("%lld %lld",&a,&b);
    c = a;
    while(b && b > c-1) b-=--c;
    for(int i=a;i>c;i--) printf("%d ",i);
    for(int i=0;i<c;i++) printf("%d ",i==c-b-1?c:i+(i<c-b));
}
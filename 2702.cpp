#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int f(int a,int b){
    if(!a) return b;
    return f(b%a,a);
}
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b; scanf("%d %d",&a,&b);
        printf("%d %d\n",a*b/f(a,b),f(a,b));
    }
}

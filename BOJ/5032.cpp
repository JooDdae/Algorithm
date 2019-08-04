#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    a += b;
    while(a/c){
        ans += a/c;
        a = a%c + a/c;
    }
    printf("%d",ans);
}

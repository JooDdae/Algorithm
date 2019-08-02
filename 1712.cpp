#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
int main(){
    scanf("%d %d %d",&a,&b,&c);
    if(b >= c) return !printf("-1");
    printf("%d",a/(c-b)+1);
}

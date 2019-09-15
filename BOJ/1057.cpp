#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c;
int main(){
    scanf("%*d %d %d",&b,&c);
    while(b!=c) b=(b+1)/2, c=(c+1)/2, ++a;
    printf("%d",a);
}
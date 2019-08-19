#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    printf("%d",max(0,d-a)+max(0,e-b)+max(0,f-c));
}
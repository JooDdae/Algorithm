#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    while(b>0 && d>0) b-=c,d-=a;
    if(b<=0 && d<=0) printf("DRAW");
    else if(b<=0) printf("PLAYER B");
    else printf("PLAYER A");
}
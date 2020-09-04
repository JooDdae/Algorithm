#include<bits/stdc++.h>
using namespace std;
int n,a[1001001],d[2002002],front=1000000,back=1000000;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=n;i>=1;i--){
        if(a[i] == 1) d[--front] = i;
        if(a[i] == 3) d[back++] = i;
        if(a[i] == 2){
            d[front-1] = d[front];
            d[front] = i;
            front--;
        }
    }
    while(front < back) printf("%d ",n-d[front++]+1);
}
#include<bits/stdc++.h>
using namespace std;
int d[10];
int main(){
    for(int i=2;i<=5;i++) scanf("%d",&d[i]);
    for(int i=2;i<=5;i++) d[i]+=d[i-1];
    for(int i=1;i<=5;i++){
    	for(int j=1;j<=5;j++) printf("%d ",i>j?d[i]-d[j]:d[j]-d[i]);
    	puts("");
    }
}
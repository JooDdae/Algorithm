#include<bits/stdc++.h>
using namespace std;
int a,b,cnt;
int main(){
    scanf("%d %d",&a,&b);
    if(b==1){
    	if(a < 0) return !printf("INFINITE");
    	return !printf("0");
    }
    if(b%2) return !printf("ERROR");
    while(1){
    	a -= b/2;
    	if(a <= 0) return !printf("%d",cnt);
    	if(b==0) return !printf("INFINITE");
    	cnt++;
    }
}
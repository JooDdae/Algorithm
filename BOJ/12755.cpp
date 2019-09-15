#include<bits/stdc++.h>
using namespace std;
int n,l=1,pl;
int f(int a,int b){
    if(!b) b+=pl;
    while(b != pl) a/=10,b++;
    return a%10;
}
int main(){
    scanf("%d",&n);
    while(++pl){
        if(n <= 9*l*pl){
            return !printf("%d",f((n-1)/pl+l,n%pl));
    	}

        n-=9*l*pl;
        l*=10;
    }
}
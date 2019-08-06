#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	if(n%2) n++;
    	n/=2;
    	printf("%d\n",n*n);
    }
}
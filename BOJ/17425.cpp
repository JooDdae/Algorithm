#include<bits/stdc++.h>
using namespace std;
int n,t;
long long a[1000001];
int main(){
    for(int j=1;j<=1000000;j++){
    	for(int i=1;i*i<=j;i++) if(j%i == 0) a[j] += i + j/i - (i==j/i?i:0);
    	a[j] += a[j-1];
    }
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	printf("%lld\n",a[n]);
    }
}
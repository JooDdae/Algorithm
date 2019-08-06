#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[1010];
int gcd(int a,int b){
	if(!a) return b;
	return gcd(b%a,a);
}
int main(){
	cnt[1] = 2;
	for(int i=1;i<=1000;i++) for(int j=1;j<=1000;j++) if(gcd(i,j) == 1) cnt[max(i,j)]++;
	for(int i=2;i<=1000;i++) cnt[i]+=cnt[i-1];
    scanf("%d",&t);
    while(t--){
    	scanf("%d",&n);
    	printf("%d\n",cnt[n]);
    }
}
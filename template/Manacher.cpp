//boj.kr/11046
#include<bits/stdc++.h>
using namespace std;
int n,a[2002002],p[2002002],r,k,q;
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n*2;i+=2) scanf("%d",a+i);

	for(int i=1;i<=n*2+1;i++){
		p[i] = max(min(r-i, p[2*k-i]), 0);
        while(i-p[i]>1 && i+p[i]<n*2+1 && a[i-p[i]-1]==a[i+p[i]+1]) p[i]++;
        if(i+p[i] > r) r=i+p[i],k=i;
	}

	scanf("%d",&q);
	while(q--){
		int b,c; scanf("%d %d",&b,&c);
		printf("%d\n",p[b+c] >= c-b);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk[400400];
int main(){
	chk[1] = 1;
	for(int i=2;i<=123456*2;i++){
		if(chk[i]) continue;
		for(int j=i+i;j<=123456*2;j+=i) chk[j] = 1;
	}
	for(int i=1;i<=123456*2;i++) chk[i] = chk[i-1] + !chk[i];
	while(1){
		scanf("%d",&n);
		if(!n) break;
		printf("%d\n",chk[2*n]-chk[n]);
	}
}
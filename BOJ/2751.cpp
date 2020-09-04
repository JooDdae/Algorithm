#include<bits/stdc++.h>
using namespace std;
int n, chk[2002002], mid=1000000;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a; scanf("%d",&a);
		chk[a+mid]++;
	}
	for(int i=0;i<=2000000;i++) while(chk[i]--) printf("%d\n",i-mid);
}
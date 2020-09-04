#include<bits/stdc++.h>
using namespace std;
int n, m, chk[1001001];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=2;i<=m;i++){
		if(chk[i]) continue;
		if(i >= n) printf("%d\n",i);
		for(int j=i+i;j<=m;j+=i) chk[j] = 1;
	}
}
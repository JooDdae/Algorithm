#include<bits/stdc++.h>
using namespace std;
int n,q,sp[22][202020];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&sp[0][i]);
    for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) sp[j][i] = sp[j-1][sp[j-1][i]];
    scanf("%d",&q);
	while(q--){
		int a,b; scanf("%d %d",&a,&b);
		for(int i=0;i<=20;i++) if((1<<i)&a) b = sp[i][b];
		printf("%d\n",b);
	}
}
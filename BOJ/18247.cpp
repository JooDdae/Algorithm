#include<cstdio>
int t,n,m;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		if(n<12 || m<4) puts("-1");
		else printf("%d\n",m*11+4);
	}
}
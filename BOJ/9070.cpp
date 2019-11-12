#include<cstdio>
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int mn1=1,mn2=5050;
		while(n--){
			int a,b; scanf("%d %d",&a,&b);
			if(a*mn2 > b*mn1 || (a*mn2 == b*mn1 && b<mn2)) mn1=a,mn2=b;
		}
		printf("%d\n",mn2);
	}
}
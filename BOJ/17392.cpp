#include<cstdio>
int n,m,ans;
int f(int a){
	return a*(a+1)*(2*a+1)/6;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
    	int a; scanf("%d",&a);
    	m -= a+1;
    }
    if(m <= 0) return !printf("0");
	for(int i=1;i<=n+1;i++) ans += f(m/(n+1)+(i<=m%(n+1)?1:0));
	printf("%d",ans);
}
#include<cstdio>
int n,m,a[11],cnt;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
    	cnt += m/a[i];
    	m%=a[i];
    }
    printf("%d",cnt);
}
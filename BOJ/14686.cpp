#include<cstdio>
int n,a[101010],b[101010],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) if((a[i]+=a[i-1]) == (b[i]+=b[i-1])) ans=i;
    printf("%d",ans);
}
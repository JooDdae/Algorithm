#include<cstdio>
long long a[20],b=1,c,n;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=n;i>=1;i--) b^=c^=b^=c,b+=c*a[i];
    printf("%lld %lld",b-c,b);
}
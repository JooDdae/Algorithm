#include<stdio.h>
long long f[91],n;
int main()
{
    f[1]=1;
    scanf("%lld",&n);
    for(int i=2;i<=n;i++) f[i]=f[i-1]+f[i-2];
    printf("%lld",f[n]);
}

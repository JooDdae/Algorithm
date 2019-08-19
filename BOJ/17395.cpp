#include<cstdio>
long long n,m;
int main(){
    scanf("%lld %lld",&n,&m);
    if(__builtin_popcountll(n) < m) return !printf("-1");
    while(--m) printf("%lld ",n-=1ll<<(63-__builtin_clzll(n)));
    printf("0");
}
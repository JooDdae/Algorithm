#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[300300],cnt,ans;
int main(){
    scanf("%d",&n);
    if(!n) return !printf("0");
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1, a+1+n);
    cnt = n*15/100 + (n*150%1000 >= 500?1 : 0);
    for(int i=cnt+1;i<=n-cnt;i++) ans += a[i];
    n-=2*cnt;
    ans *= 10;
    printf("%d",ans/n/10 + (ans/n%10>=5? 1 : 0));
}
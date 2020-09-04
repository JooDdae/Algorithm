#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
ll m,a[1001001];
int main(){
    scanf("%d %d %lld",&n,&k,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        if(a[i] >= 2*k) a[i] -= 2*k;
        else if(a[i] >= k) a[i] -= k;
        else a[i] = 0;
    }

    int l = 1, r = 1e9;

    while(l <= r){
        int mid = (l+r)/2;
        ll cnt = 0;
        for(int i=1;i<=n;i++) cnt += a[i] / mid;

        if(cnt < m) r = mid-1;
        else l = mid+1;
    }

    if(l == 1) printf("-1");
    else printf("%d",l-1);
}
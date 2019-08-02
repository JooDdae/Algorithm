#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll arr[101010];
int f(ll l,ll r){
    if(l==r) return arr[l];
    ll mid=(l+r)/2;
    ll re = max(f(l,mid),f(mid+1,r));
    ll h=min(arr[mid] , arr[mid+1]),lw = mid,hi=mid+1;
    re=max(re,2 * h);
    while(l<lw || hi<r){
        if(hi<r && (lw==l || arr[hi+1] > arr[lw-1])){
            hi++;
            h=min(h,arr[hi]);
            re=max(re,h*(hi-lw+1));
        }else{
            lw--;
            h=min(h,arr[lw]);
            re=max(re,h*(hi-lw+1));
        }
    }
    return re;
}

int main(){
    while(1){
        scanf("%d",&n);
        if(!n) break;
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);

        printf("%lld\n",f(1,n));
    }
}
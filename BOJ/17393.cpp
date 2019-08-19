#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[505050],b[505050];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) printf("%d ",upper_bound(b+i,b+1+n,a[i])-b-i-1);
}
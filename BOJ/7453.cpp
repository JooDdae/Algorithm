#include<bits/stdc++.h>
using namespace std;
int n,a[4040],b[4040],c[4040],d[4040];
long long cnt;
vector<int> v1,v2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) v2.push_back(c[i]+d[j]);
    sort(v2.begin(),v2.end());
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cnt += upper_bound(v2.begin(),v2.end(),-a[i]-b[j]) - lower_bound(v2.begin(),v2.end(),-a[i]-b[j]);
    printf("%lld",cnt);
}
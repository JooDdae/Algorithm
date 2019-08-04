#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,l[3030],d[3030],ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&l[i],&d[i]);

    for(int i=2;i<=n;i++){
        if(d[i] == d[i-1]) continue;
        ans = max(ans, (m-l[i]-l[i-1])/2);
    }
    printf("%d",ans);
}

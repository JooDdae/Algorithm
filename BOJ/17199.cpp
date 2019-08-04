#include<bits/stdc++.h>
using namespace std;
int n,nxt[111];
vector<int> v[111];
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b; scanf("%d %d",&a,&b);
        if(nxt[a]) return !printf("-1");
        nxt[a] = b;
    }
    for(int i=1;i<=n;i++) if(!nxt[i]) printf("%d",i);
}

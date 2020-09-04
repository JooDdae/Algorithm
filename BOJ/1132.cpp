#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk2[256],cnt;
ll ans,chk[256];
char s[50];
vector<pair<ll,int>> v;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll t=1;
        scanf(" %s",s);
        for(int j=strlen(s)-1;j>=0;j--){
            chk[s[j]]+=t;
            t*=10;
        }
        chk2[s[0]] = 1;
    }
    for(int i='A';i<='J';i++) v.push_back({chk[i], chk2[i]});
    sort(v.begin(), v.end(), greater<pair<ll,int>>());
    int cur = 9;
    while(v[cur].second) cur--;
    for(int i=0;i<10;i++) if(i != cur) ans += v[i].first * (9-i+(i>cur));
    printf("%lld",ans);
}

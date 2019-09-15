#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,fl;
pair<ll,ll> p[101010];
ll ans,mx,mx2,l;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i].second);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i].first);
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++){
        mx = max(mx, p[i].first);
    	if(mx>p[i].second){
    		int f = (mx-p[i].second)/30+((mx-p[i].second)%30?1:0);
    		ans+=f, p[i].second+=f*30;
    	}
    	if(p[i].first != p[i+1].first) mx=max({mx, p[i].second, mx2});
    	else mx2=max(mx2, p[i].second);
    	l = p[i].first;
    }
    printf("%lld",ans);
}
#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
pair<int,int> p[25252];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&p[i].first,&p[i].second);
    sort(p+1,p+1+n);
    int l=1,cur=0;
    while(cur < m){
        int nxt=0;
        while(l<=n && p[l].first<=cur+1) nxt = max(nxt, p[l++].second);
        if(!nxt) return !printf("-1");
        ans++;
        cur=nxt;
    }
    printf("%d",ans);
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x[222],y[222];
set<pair<int,int>> s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d %d",&a,&b);
        s.insert({a,b});
    }
    for(auto it=s.begin();it!=s.end();it++){
        int fl=0,xx=x[1]-(*it).first,yy=y[1]-(*it).second;
        for(int i=2;i<=n;i++) if(!s.count({x[i]-xx,y[i]-yy})) fl=1;
        if(!fl) return !printf("%d %d",-xx,-yy);
    }
}

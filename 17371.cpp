#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[1111],y[1111],mn=1e9,id;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=1;j<=n;j++) mx=max(mx, (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        if(mx<mn) mn=mx,id=i;
    }
    printf("%d %d",x[id],y[id]);
}

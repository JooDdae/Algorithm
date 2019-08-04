#include <bits/stdc++.h>
using namespace std;
int x[4],y[4];
double ans = 1e9;
void f(int cur,int bit,int cnt,double dis){
    if(cnt == 4){
        ans = min(ans, dis);
        return;
    }
    for(int i=1;i<4;i++){
        if(bit & (1<<i)) continue;
        f(i, bit|(1<<i), cnt+1, dis+sqrt((x[cur]-x[i])*(x[cur]-x[i])+(y[cur]-y[i])*(y[cur]-y[i])));
    }
}
int main(){
    for(int i=0;i<4;i++) scanf("%d %d",&x[i],&y[i]);
    f(0,1,1,0);
    printf("%.0f",floor(ans));
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x[3030][2],y[3030][2],chk[3030],cnt,mx;
int ccw(int a,int b,int c,int d,int e,int f){
    int o = x[a][b]*y[c][d] + x[c][d]*y[e][f] + x[e][f]*y[a][b] - y[a][b]*x[c][d] - y[c][d]*x[e][f] - y[e][f]*x[a][b];
    if(o < 0) return -1;
    if(o > 0) return 1;
    return 0;
}
int c(int aa,int bb){
    int a = ccw(aa,0,aa,1,bb,0) * ccw(aa,0,aa,1,bb,1);
    int b = ccw(bb,0,bb,1,aa,0) * ccw(bb,0,bb,1,aa,1);
    if(a == 0 && b == 0){
        return max(tie(x[aa][0],y[aa][0]),tie(x[aa][1],y[aa][1])) >= min(tie(x[bb][0],y[bb][0]),tie(x[bb][1],y[bb][1]))
            && min(tie(x[aa][0],y[aa][0]),tie(x[aa][1],y[aa][1])) <= max(tie(x[bb][0],y[bb][0]),tie(x[bb][1],y[bb][1]));
    }
    return a<=0 && b<=0;
}
int f(int cur){
    chk[cur] = 1;
    int re = 1;
    for(int i=1;i<=n;i++){
        if(i == cur || chk[i]) continue;
        if(c(cur,i)) re += f(i);
    }
    return re;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=0;j<2;j++) scanf("%d %d",&x[i][j],&y[i][j]);
    for(int i=1;i<=n;i++){
        if(!chk[i]){
            cnt++;
            mx = max(mx, f(i));
        }
    }
    printf("%d\n%d",cnt,mx);
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,x[4],y[4];
int ccw(int a,int b,int c,int d,int e,int f){
    int o = a*d+c*f+e*b-b*c-d*e-f*a;
    if(o<0) return -1;
    if(o>0) return 1;
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<4;i++) scanf("%d %d",&x[i],&y[i]);
        if(x[2] > x[3]) swap(x[2],x[3]);
        if(y[2] > y[3]) swap(y[2],y[3]);
        int fl=0;
        if((x[2]<=x[0]&&x[0]<=x[3]&&y[2]<=y[0]&&y[0]<=y[3])||(x[2]<=x[1]&&x[1]<=x[3]&&y[2]<=y[1]&&y[1]<=y[3])) fl = 1;
        else if(ccw(x[2],y[2],x[3],y[2],x[0],y[0]) != ccw(x[2],y[2],x[3],y[2],x[1],y[1]) && ccw(x[0],y[0],x[1],y[1],x[2],y[2]) != ccw(x[0],y[0],x[1],y[1],x[3],y[2])) fl = 1;
        else if(ccw(x[3],y[2],x[3],y[3],x[0],y[0]) != ccw(x[3],y[2],x[3],y[3],x[1],y[1]) && ccw(x[0],y[0],x[1],y[1],x[3],y[2]) != ccw(x[0],y[0],x[1],y[1],x[3],y[3])) fl = 1;
        else if(ccw(x[3],y[3],x[2],y[3],x[0],y[0]) != ccw(x[3],y[3],x[2],y[3],x[1],y[1]) && ccw(x[0],y[0],x[1],y[1],x[3],y[3]) != ccw(x[0],y[0],x[1],y[1],x[2],y[3])) fl = 1;
        else if(ccw(x[2],y[3],x[2],y[2],x[0],y[0]) != ccw(x[2],y[3],x[2],y[2],x[1],y[1]) && ccw(x[0],y[0],x[1],y[1],x[2],y[3]) != ccw(x[0],y[0],x[1],y[1],x[2],y[2])) fl = 1;
        printf("%c\n",(fl?'T':'F'));
    }
}

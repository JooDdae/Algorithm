#include <bits/stdc++.h>
using namespace std;
int n,m,w[20][20],chk[20][20],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
char mp[20][20];
queue<int> qx,qy,qc;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=10;i++) scanf("%s",mp[i]+1);
    for(int i=1;i<=10;i++) for(int j=1;j<=10;j++) if(mp[i][j] == 'o') for(int k=1;k<=10;k++) w[i][k]=w[k][j]=1;
    qx.push(n),qy.push(m),qc.push(0);
    chk[n][m] = 1;
    while(!qx.empty()){
        int x=qx.front(),y=qy.front(),c=qc.front();
        qx.pop(),qy.pop(),qc.pop();
        if(!w[x][y]) return !printf("%d",c);

        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1 || yy<1 || xx>10 || yy>10 || chk[xx][yy]) continue;
            qx.push(xx),qy.push(yy),qc.push(c+1);
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
int n,m,dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,-1,1,1,-1,1,-1},cnt,chk[2020][2020],col[4040404];
char s[2020][2020];
void f(int x,int y,int t){
    chk[x][y] = t;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(chk[xx][yy] || s[xx][yy]=='.') continue;
        f(xx,yy,t);
    }
}
void f2(int x,int y){
    chk[x][y] = 1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(s[xx][yy] == '#') col[chk[xx][yy]] = 1;
        if(xx<1 || yy<1 || xx>n || yy>m || chk[xx][yy]) continue;
        f2(xx,yy);
    }
    for(int i=4;i<8;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1 || yy<1 || xx>n || yy>m || chk[xx][yy] || chk[xx][y] == chk[x][yy]) continue;
        f2(xx,yy);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j] == '#' && !chk[i][j]) f(i,j,++cnt);
    f2(1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%c",(s[i][j]=='.'?'.':col[chk[i][j]]?'O':'X'));
        puts("");
    }
}

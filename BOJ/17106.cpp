#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n=5, c[10][10], x[10], y[10], l, r, ch[10][10];

int bingosum(){
    int re = 0;
    memset(ch, 0, sizeof(ch));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(y[i] || x[j]) ch[i][j] = 1, re++;
    if(l) for(int i=1;i<=n;i++) if(!ch[i][i]) ch[i][i] = 1, re++;
    if(r) for(int i=1;i<=n;i++) if(!ch[i][5-i+1]) ch[i][5-i+1] = 1, re++;
    return re;
}

bool chk(){
    l = c[1][1] & c[2][2] & c[3][3] & c[4][4] & c[5][5];
    r = c[5][1] & c[4][2] & c[3][3] & c[2][4] & c[1][5];
    for(int i=1;i<=5;i++) x[i] = c[i][1] & c[i][2] & c[i][3] & c[i][4] & c[i][5];
    for(int i=1;i<=5;i++) y[i] = c[1][i] & c[2][i] & c[3][i] & c[4][i] & c[5][i];
    int X = 0, Y = 0;
    for(int i=1;i<=5;i++) X += x[i], Y += y[i];
    int S[2] = {0, 0};
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) S[c[i][j]]++;
    int sumc = 0;
    for(int i=1;i<=5;i++) sumc += c[3][i];
    int cnb = 0;
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) if(c[i][j] && !x[i] && !y[j] && !(i==j && l) && !(5-i+1==j && r)) cnb++;
    int nb = 0;
    for(int i=1;i<=5;i++) for(int j=1;j<=5;j++) if(!x[i] && !y[j] && !(i==j && l) && !(5-i+1==j && r)) nb++;
    

    if(c[1][1] && r) return 0;
    if(!c[1][1] && !r) return 0;

    if(c[1][2] && (x[1] || y[2])) return 0;
    if(!c[1][2] && !(x[1] || y[2])) return 0;

    if(c[1][3] && !l) return 0;
    if(!c[1][3] && l) return 0;

    if(c[1][4] && !c[4][4]) return 0;
    if(!c[1][4] && c[4][4]) return 0;

    if(c[1][5] && !(r || x[1] || y[5])) return 0;
    if(!c[1][5] && (r || x[1] || y[5])) return 0;


    if(c[2][1] && c[1][4]) return 0;
    if(!c[2][1] && !c[1][4]) return 0;

    if(c[2][2] && !((l || r) && X && Y)) return 0;
    if(!c[2][2] && ((l || r) && X && Y)) return 0;

    //c[2][3]
    //c[2][3]

    if(c[2][4] && !(S[1] <= 17)) return 0;
    if(!c[2][4] && (S[1] <= 17)) return 0;

    if(c[2][5] && (bingosum() % 2)) return 0;
    if(!c[2][5] && !(bingosum() % 2)) return 0;


    if(c[3][1] && !(x[3] || y[1])) return 0;
    if(!c[3][1] && (x[3] || y[1])) return 0;

    if(c[3][2] && !(cnb >= 5)) return 0;
    if(!c[3][2] && (cnb >= 5)) return 0;

    //c[3][3]
    if(!c[3][3]) return 0; // change

    if(c[3][4] && !(Y >= 2)) return 0;
    if(!c[3][4] && (Y >= 2)) return 0;

    if(c[3][5] && !(nb >= 10)) return 0;
    if(!c[3][5] && (nb >= 10)) return 0;


    if(c[4][1] && c[1][2]) return 0;
    if(!c[4][1] && !c[1][2]) return 0;

    if(c[4][2] && !(x[2] || y[4])) return 0;
    if(!c[4][2] && (x[2] || y[4])) return 0;

    if(c[4][3] && !(sumc <= 3)) return 0;
    if(!c[4][3] && (sumc <= 3)) return 0;

    if(c[4][4] && !c[1][4]) return 0;
    if(!c[4][4] && c[1][4]) return 0;

    if(c[4][5] && !(l || r)) return 0;
    if(!c[4][5] && (l || r)) return 0;


    if(c[5][1] && !c[5][5]) return 0;
    if(!c[5][1] && c[5][5]) return 0;

    //c[5][2]
    if(!c[5][2]) return 0; // change

    //c[5][3]
    //c[5][3]

    if(c[5][4] && !(l + r + X + Y >= 3)) return 0;
    if(!c[5][4] && (l + r + X + Y >= 3)) return 0;

    if(c[5][5] && !c[5][1]) return 0;
    if(!c[5][5] && c[5][1]) return 0;

    return 1;
}

bool f(int x, int y){
    if(y > 5) x++, y=1;
    if(x > 5) return chk();

    c[x][y] = 0;
    if(f(x, y+1)) return 1;
    c[x][y] = 1;
    if(f(x, y+1)) return 1;
    return 0;
}

int main(){
    f(1, 1);
    for(int i=1;i<=5;i++,puts("")) for(int j=1;j<=5;j++) printf("%c",c[i][j]?'#':'.');
}
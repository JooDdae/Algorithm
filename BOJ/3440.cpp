#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char mp[222][222];
int chk[222][222], p[400400], type[400400], cur[400400];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, int d, int cnt){
    if(mp[x][y] == '+'){
        chk[x][y] = cnt;
        for(int i=0;i<4;i++) if(!chk[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i], i, cnt);
    }
    if(mp[x][y] == 'x'){
        chk[x][y] = cnt;
        dfs(x+dx[d], y+dy[d], d, cnt);
    }
    if(mp[x][y] == '|' && d % 2 == 1){
        chk[x][y] = cnt;
        dfs(x+dx[d], y+dy[d], d, cnt);
    }
    if(mp[x][y] == '-' && d % 2 == 0){
        chk[x][y] = cnt;
        dfs(x+dx[d], y+dy[d], d, cnt);
    }
}

int Gate(int x, int y, int cnt){
    while(mp[x-1][y] == '#') x--;
    while(mp[x][y-1] == '#') y--;
    while(mp[x-1][y] == '#') x--;

    int xx = x, yy = y;
    while(mp[xx+1][y] == '#') xx++;
    while(mp[x][yy+1] == '#') yy++;

    int re = 0;
    for(int i=x;i<=xx;i++){
        for(int j=y;j<=yy;j++){
            chk[i][j] = cnt;
            if(mp[i][j] != '#' && mp[i][j] != ' ') re = mp[i][j];
        }
        if(mp[i][yy+1] == 'o') chk[i][yy+1] = cnt;
    }
    return re;
}

int find_type(int x, int y, int d, int cnt){
    chk[x][y] = cnt;
    if(mp[x][y] == '0') return '0';
    if(mp[x][y] == '1'){
        cur[cnt] = 1;
        return '1';
    }
    if('A'<=mp[x][y] && mp[x][y]<='Z') return mp[x][y];

    if(mp[x][y] == '+' || mp[x][y] == '-'){
        dfs(x, y, d, cnt);
        return 0;
    }

    if(mp[x][y] == 'o') y--;
    int g = Gate(x, y, cnt);
    if(g == '&') cur[cnt] = 1;
    return g;
}

bool chk_gate(int x, int y){
    int X = x, Y = y;
    while(mp[x][y] == '=' || mp[x][y] == ' ') y--;
    if(mp[x][y] != '#') return false;

    while(mp[x-1][y] == '#') x--;
    while(mp[x][y-1] == '#') y--;
    while(mp[x-1][y] == '#') x--;

    int xx = x, yy = y;
    while(mp[xx+1][y] == '#') xx++;
    while(mp[x][yy+1] == '#') yy++;


    return (x < X && X < xx && y < Y && Y < yy);
}

int main(){
    while(fgets(mp[1]+1, 221, stdin)){
        if(mp[1][1] == '*') continue;
        int n = 1, m = strlen(mp[1]+1);
        while(++n){
            fgets(mp[n]+1, 221, stdin);
            if(mp[n][1] == '*') break;
            m = max(m, (int)strlen(mp[n]+1));
        }
        n--;
        memset(chk, 0, sizeof(chk));
        memset(p, 0, sizeof(p));
        memset(type, 0, sizeof(type));
        memset(cur, 0, sizeof(cur));

        vector<int> v[n*m];
        vector<int> op[n*m];
        map<char, int> ans;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mp[i][j] == '='){
                    if(chk_gate(i, j)) continue;

                    if(mp[i][j+1] == '=') j++;

                    int pl = mp[i][j-1] == '=';
                    if(!chk[i][j-1-pl]) ++cnt, type[cnt] = find_type(i, j-1-pl, 2, cnt);
                    if(!chk[i][j+1]) ++cnt, type[cnt] = find_type(i, j+1, 0, cnt);
                    v[chk[i][j-1-pl]].push_back(chk[i][j+1]);
                    op[chk[i][j-1-pl]].push_back(mp[i][j-1-pl] == 'o');
                    p[chk[i][j+1]]++;
                }
            }
        }

        queue<int> q;
        for(int i=1;i<=cnt;i++) if(!p[i]) q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            
            int i = 0;
            for(auto x : v[u]){
                if(op[u][i]) cur[u] = !cur[u];

                if(type[x] == '&') cur[x] &= cur[u];
                if(type[x] == '=') cur[x] ^= cur[u];
                if(type[x] == '1') cur[x] |= cur[u];
                if(!type[x]) cur[x] |= cur[u];
                if('A'<=type[x] && type[x]<='Z') ans[type[x]] = cur[u];

                if(--p[x] == 0) q.push(x);
                if(op[u][i]) cur[u] = !cur[u];
                i++;
            }
        }

        for(auto it : ans) printf("%c=%d\n",it.first,it.second);
        puts("");
    }
}
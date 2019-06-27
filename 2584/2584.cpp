#include <bits/stdc++.h>
using namespace std;
int n,m,dp[1010][1010][2],tmp[1010][2],fl2;
vector<pair<int,int>> v[1010];
vector<int> son[1010];
vector<vector<pair<int, int>>> bt[1010][2];
set<int> s;
int sz[1010];
void f(int cur,int par){
    for(pair<int,int> nxt : v[cur]){
        if(par == nxt.first) continue;
        f(nxt.first, cur);

        bt[cur][0].push_back(vector<pair<int, int>>(1010, {-1, -1}));
        bt[cur][1].push_back(vector<pair<int, int>>(1010, {-1, -1}));
        son[cur].push_back(nxt.first);
        int cnt = bt[cur][0].size()-1;

        for(int i=0;i<=m;i++) tmp[i][0]=tmp[i][1]=1e9;

        for(int i=0;i<=sz[cur];i++){
            if(i != 0 && dp[cur][i][0] == 1e9 && dp[cur][i][1] == 1e9) break;
            for(int j=0;j<=sz[nxt.first];j++){
                if(j != 0 && dp[nxt.first][j][0] == 1e9 && dp[nxt.first][j][1] == 1e9) break;
                if(tmp[i+j][1] > dp[cur][i][1]+dp[nxt.first][j][1]+nxt.second){
                    tmp[i+j][1] = dp[cur][i][1]+dp[nxt.first][j][1]+nxt.second;
                    bt[cur][1][cnt][i+j] = {j, 1};
                }
                if(tmp[i+j][1] > dp[cur][i][1]+dp[nxt.first][j][0]){
                    tmp[i+j][1] = dp[cur][i][1]+dp[nxt.first][j][0];
                    bt[cur][1][cnt][i+j] = {j, 0};
                }
                if(tmp[i+j][0] > dp[cur][i][0]+dp[nxt.first][j][1]){
                    tmp[i+j][0] = dp[cur][i][0]+dp[nxt.first][j][1];
                    bt[cur][0][cnt][i+j] = {j, 1};
                }
                if(tmp[i+j][0] > dp[cur][i][0]+dp[nxt.first][j][0]+nxt.second){
                    tmp[i+j][0] = dp[cur][i][0]+dp[nxt.first][j][0]+nxt.second;
                    bt[cur][0][cnt][i+j] = {j, 0};
                }
            }

            sz[cur] += sz[nxt.first];
            sz[cur] = min(m, sz[cur]);
        }

        for(int i=0;i<=m;i++) for(int j=0;j<2;j++) dp[cur][i][j] = tmp[i][j];
    }
}
void b(int cur,int cnt,int k,int fl){
    if(fl) s.insert(cur);


    if(cnt < 0 || bt[cur][fl][cnt][k].first == -1) return;

    b(son[cur][cnt],son[son[cur][cnt]].size()-1,bt[cur][fl][cnt][k].first,bt[cur][fl][cnt][k].second);
    b(cur, cnt-1, k-bt[cur][fl][cnt][k].first, fl);
}
int main(){
    scanf("%d %d",&n,&m);
    if(m >= n/2) m = n-m, fl2=1;
    for(int i=1;i<n;i++){
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++) sz[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++) dp[i][j][0]=dp[i][j][1]=1e9;
        dp[i][1][1] = 0;
        dp[i][0][0] = 0;
    }
    f(1,0);
    printf("%d\n",min(dp[1][m][0],dp[1][m][1]));
    if(dp[1][m][0] > dp[1][m][1]) b(1,v[1].size()-1,m,1);
    else b(1,v[1].size()-1,m,0);
    if(fl2){
        for(int i=1;i<=n;i++) if(!s.count(i)) printf("%d ",i);
    }
    else for(auto it=s.begin();it!=s.end();it++) printf("%d ",*it);
}

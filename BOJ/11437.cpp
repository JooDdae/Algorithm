#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,sp[20][50505],h[50505];
vector<int> v[50505];
void dfs(int cur,int c){
    h[cur] = c;
    for(int nxt : v[cur]) if(!h[nxt]){dfs(nxt,c+1); sp[0][nxt]=cur;}
}
int lca(int a,int b){
    if(h[a] > h[b]) swap(a,b);
    int val = h[b]-h[a];
    for(int i=0;i<=17;i++) if(val & (1<<i)) b = sp[i][b];
    if(a == b) return a;
    for(int i=17;i>=0;i--) if(sp[i][a]!=sp[i][b]) a = sp[i][a],b = sp[i][b];
    return sp[0][a];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,1);
    for(int i=1;i<=17;i++) for(int j=1;j<=n;j++) sp[i][j] = sp[i-1][sp[i-1][j]];
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d %d",&a,&b);
        printf("%d\n",lca(a,b));
    }
}

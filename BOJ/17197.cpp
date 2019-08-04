#include<bits/stdc++.h>
using namespace std;
int x[101010],y[101010],n,m,chk[101010],ans=1e9;
vector<int> v[101010];
queue<int> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    for(int i=1;i<=m;i++){
        int a,b; scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(!chk[i]){
        int mx[2]={0,100000000},my[2]={0,100000000};
        chk[i] = 1;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            mx[0]=max(mx[0],x[cur]);
            mx[1]=min(mx[1],x[cur]);
            my[0]=max(my[0],y[cur]);
            my[1]=min(my[1],y[cur]);
            for(int nxt : v[cur]) if(!chk[nxt]){
                chk[nxt] = 1;
                q.push(nxt);
            }
        }
        ans =min(ans, 2*(mx[0]-mx[1]+my[0]-my[1]));
    }
    printf("%d",ans);
}

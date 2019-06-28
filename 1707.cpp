#include <bits/stdc++.h>
using namespace std;
int t,n,m,chk[20202];
vector<int> v[20202];
int main(){
    scanf("%d",&t);
    while(t--){
        queue<int> q,qc;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) chk[i] = -1;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=m;i++){
            int a,b; scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int fl=0;
        for(int i=1;i<=n;i++){
            if(chk[i] != -1) continue;

            q.push(i),qc.push(1);
            chk[i] = 1;
            while(!q.empty()){
                int cur = q.front(),col = qc.front();
                q.pop(),qc.pop();

                for(int nxt : v[cur]){
                    if(chk[nxt] != -1){
                        if(chk[nxt] == col) fl = 1;
                        continue;
                    }
                    chk[nxt] = !col;
                    q.push(nxt),qc.push(!col);
                }
            }

            if(fl) break;
        }
        printf("%s\n",(fl?"NO":"YES"));
    }
}

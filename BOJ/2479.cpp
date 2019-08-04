#include<bits/stdc++.h>
using namespace std;
int n,k,s,e,chk[1010],arr[1010],dis[1010][1010];
queue<int> q;
vector<int> v[1010];
void f(int a){
    if(a == -1) return;
    f(chk[a]);
    printf("%d ",a);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            int a; scanf("%01d",&a);
            if(a) arr[i] += 1<<j;
        }
    }
    scanf("%d %d",&s,&e);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int bit = arr[i] ^ arr[j];
            while(bit){
                dis[i][j] += bit&1;
                bit>>=1;
            }
            if(dis[i][j] <= 1) v[i].push_back(j),v[j].push_back(i);
        }
    }
    q.push(s);
    chk[s] = -1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        if(cur == e){
            f(e);
            return 0;
        }

        for(int nxt : v[cur]){
            if(chk[nxt]) continue;
            chk[nxt] = cur;
            q.push(nxt);
        }
    }
    printf("-1");
}

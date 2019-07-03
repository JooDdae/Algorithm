#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,post[101010],pre[101010],cnt,fl;
vector<int> v[101010];
void f(int cur){
    pre[cur] = ++cnt;
    for(int nxt : v[cur]){
        if(pre[nxt]){
            if(!post[nxt]) fl = 1;
        }
        else f(nxt);
    }
    post[cur] = ++cnt;
}
int main(){
    scanf("%d %d %d",&n,&m1,&m2);
    for(int i=1;i<=m1;i++){
        int a,b; scanf("%d %d",&a,&b);
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!post[i]) f(i);
        if(fl) return !printf("-1");
    }
    for(int i=1;i<=m2;i++){
        int a,b; scanf("%d %d",&a,&b);
        if(post[a] < post[b]) swap(a,b);
        printf("%d %d\n",a,b);
    }
}

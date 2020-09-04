#include<bits/stdc++.h>
using namespace std;
int t, n, a[100100], cnt;
int trie[3200000][2];

void update(int x){
    int cur = 0;
    for(int i=31;i>=0;i--){
        int fl = ((1<<i)&x)?1:0;
        if(!trie[cur][fl]) trie[cur][fl] = ++cnt;
        cur = trie[cur][fl];
    }
}

int find(int x){
    int cur = 0, re = 0;
    for(int i=31;i>=0;i--){
        int fl = ((1<<i)&x)?1:0;
        if(!trie[cur][1]) cur = trie[cur][0], re += fl ? 1<<i : 0;
        else if(!trie[cur][0]) cur = trie[cur][1], re += fl ? 0 : 1<<i;
        else cur = trie[cur][!fl], re += 1<<i;
    }
    return re;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        update(0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            a[i] ^= a[i-1];
            ans = max(ans, find(a[i]));
            update(a[i]);
        }

        printf("%d\n",ans);

        for(int i=0;i<=cnt;i++) trie[i][0] = trie[i][1] = 0;
        cnt = 0;
    }
}
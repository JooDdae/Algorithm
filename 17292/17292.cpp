#include <bits/stdc++.h>
using namespace std;
int a[6];
char b[6],in[20];
struct node{
    int f,s;
    bool operator < (const node &nx)const{
        if((a[f]%15+1 == a[s] || a[f] == a[s]%15+1) || (a[nx.f]%15+1 == a[nx.s] || a[nx.f] == a[nx.s]%15+1)){
            if((a[f]%15+1 == a[s]||a[f] == a[s]%15+1) ^ (a[nx.f]%15+1 == a[nx.s]||a[nx.f] == a[nx.s]%15+1)) return (a[f]%15+1 == a[s]||a[f] == a[s]%15+1) < (a[nx.f]%15+1 == a[nx.s]||a[nx.f] == a[nx.s]%15+1);
        }else if((a[f] == a[s]) ^ (a[nx.f] == a[nx.s])) return (a[f] == a[s]) < (a[nx.f] == a[nx.s]);

        if((b[f] == b[s]) ^ (b[nx.f] == b[nx.s])) return (b[f] == b[s]) < (b[nx.f] == b[nx.s]);
        if(max(a[f],a[s]) != max(a[nx.f],a[nx.s])) return max(a[f],a[s]) < max(a[nx.f],a[nx.s]);
        if(min(a[f],a[s]) != min(a[nx.f],a[nx.s])) return min(a[f],a[s]) < min(a[nx.f],a[nx.s]);

        if(b[(a[f] > a[s])?f:s] == 'b') return false;
        return true;
    }
};
priority_queue<node> pq;
int main(){
    scanf("%s",in);
    for(int i=0;i<6;i++){
        if('0'<=in[i*3] && in[i*3]<='9') a[i] = in[i*3]-'0';
        else a[i] = in[i*3]-'a'+10;
        b[i] = in[i*3+1];
    }
    for(int i=0;i<6;i++) for(int j=i+1;j<6;j++) pq.push({i,j});

    while(!pq.empty()){
        int f=pq.top().f,s=pq.top().s;
        pq.pop();
        printf("%x%c%x%c\n",a[f],b[f],a[s],b[s]);
    }
}

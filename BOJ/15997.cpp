#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string,int> mp;
char A[20],B[20];
int sc[5],pl[4][2]={{0,0},{3,0},{1,1},{0,3}};
double v[5][5][5],w[5];
void f(int cur,int nxt,double p){
    nxt++;
    if(nxt > 4) nxt = ++cur+1;
    if(cur == 4){
        priority_queue<pair<int,int>> pq;
        vector<int> n;
        for(int i=1;i<=4;i++) pq.push({sc[i],i});
        int mx = pq.top().first;
        while(!pq.empty() && pq.top().first == mx){
            n.push_back(pq.top().second);
            pq.pop();
        }

        if(n.size() >= 2) for(int nxt : n) w[nxt] += p*2/n.size();
        else{
            w[n[0]] += p;
            n.clear();
            mx = pq.top().first;
            while(!pq.empty() && pq.top().first == mx){
                n.push_back(pq.top().second);
                pq.pop();
            }
            for(int nxt : n) w[nxt] += p/n.size();
        }
        return;
    }

    for(int i=1;i<=3;i++){
        if(v[cur][nxt][i] <= 0) continue;
        sc[cur]+=pl[i][0],sc[nxt]+=pl[i][1];
        f(cur,nxt,p*v[cur][nxt][i]);
        sc[cur]-=pl[i][0],sc[nxt]-=pl[i][1];
    }
}
int main(){
    for(int i=1;i<=4;i++){
        scanf("%s",A);
        mp[A] = i;
    }
    for(int i=1;i<=6;i++){
        double a,b,c; scanf("%s %s %lf %lf %lf",A,B,&a,&b,&c);
        if(mp[A] > mp[B]) swap(A,B),swap(a,c);
        v[mp[A]][mp[B]][1] = a;
        v[mp[A]][mp[B]][2] = b;
        v[mp[A]][mp[B]][3] = c;
    }
    f(0,5,1);
    for(int i=1;i<=4;i++) printf("%.12f\n",w[i]);
}

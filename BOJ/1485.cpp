#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
pair<ll,ll> coor[4];
ll len(int a,int b){
    return (coor[a].first-coor[b].first)*(coor[a].first-coor[b].first)+(coor[a].second-coor[b].second)*(coor[a].second-coor[b].second);
}
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<4;i++) scanf("%lld %lld",&coor[i].first,&coor[i].second);
        sort(coor,coor+4);
        printf("%d\n",len(0,3)==len(1,2) && len(0,1)==len(0,2) && len(3,1)==len(3,2) && len(0,1)==len(3,1));
    }
}

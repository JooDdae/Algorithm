#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,chk[1010101],dx[6]={40,1,1,-40,-1,-1};
int f(int cnt,int cur,int d){
    if(!cnt){
        if(chk[cur]) return 1;
        return 0;
    }
    if(chk[cur]) return 0;

    chk[cur] = 1;
    int re=f(cnt-1,cur+dx[(d+5)%6],(d+5)%6)+f(cnt-1,cur+dx[(d+1)%6],(d+1)%6);
    chk[cur] = 0;
    return re;
}
int main(){
    scanf("%d",&n);
    chk[500000]=1;
    printf("%d",f(n,500000+dx[0],0));
}

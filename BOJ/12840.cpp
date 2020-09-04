#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,t,mod=24*60*60;
int main(){
    scanf("%d %d %d %d",&a,&b,&c,&t);
    c = a * 3600 + b * 60 + c;
    while(t--){
        int d; scanf("%d",&d);
        if(d == 1){
            int e; scanf("%d",&e);
            c = (c + e) % mod;
        }
        if(d == 2){
            int e; scanf("%d",&e);
            c = (c - e) % mod;
        }
        if(d == 3){
            while(c < 0) c += mod;
            printf("%d %d %d\n",c/60/60%24,c/60%60,c%60);
        }
    }
}
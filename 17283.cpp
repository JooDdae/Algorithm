#include <bits/stdc++.h>
using namespace std;
int n,m,ans,cnt=1;
int main(){
    scanf("%d %d",&n,&m);
    while(n*m/100 > 5){
        n = n*m/100;
        cnt *= 2;
        ans += n * cnt;
    }
    printf("%d",ans);
}

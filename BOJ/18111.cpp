#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,b,c,a[505 * 505];
int main(){
    scanf("%d %d %d",&n,&m,&b);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[++c]);
    
    int mn=1e9,ans;
    for(int i=256;i>=0;i--){
        int cur = b, time = 0;

        for(int j=1;j<=c;j++){
            if(a[j] < i){
                cur -= i - a[j];
                time += i - a[j];
            }else if(a[j] > i){
                cur += a[j] - i;
                time += (a[j] - i) * 2;
            }
        }

        if(cur >= 0 && time < mn){
            mn = time;
            ans = i;
        }
    }
    printf("%d %d",mn,ans);
}
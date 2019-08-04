#include<bits/stdc++.h>
using namespace std;
int n,fl,fl2;
char s[1010][1010];
int f(int a,int b){
    int re = 0;
    for(int i=0;i<n;i++) re += s[a][i] != s[b][i];
    return re;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",s[i]);

    for(int i=0;i<n;i++){
        int a = f(i,(i+1)%n)%n,b = f(i,(i-1+n)%n)%n;
        if((a && a!=1 && a!=n-1) || (b && b!=1 && b!=n-1)) return !printf("-1");
        if(a%n && b%n){
            if(fl) return !printf("-1");
            fl = i+1;
            fl2 = a;
        }
    }
    for(int j=0;j<n;j++) if((s[fl-1][j] != s[fl%n][j]) ^ (fl2 == n-1)) return !printf("%d %d",fl,j+1);
}

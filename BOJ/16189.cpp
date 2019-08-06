#include<bits/stdc++.h>
using namespace std;
char s[252525];
int main(){
    scanf("%s %*d",s);
    for(int i=0,n=strlen(s);i<=n/2;i++) if(s[i] != s[n-i-1]) return !printf("NO");
    printf("YES");
}
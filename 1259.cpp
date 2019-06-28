#include<bits/stdc++.h>
using namespace std;
char s[10];
int n,fl;
int main(){
    while(1){
        scanf("%s",s);
        if(!strcmp(s,"0")) break;
        n = strlen(s);
        fl = 0;
        for(int i=0;i<=n/2;i++) if(s[i] != s[n-i-1]) fl=1;
        printf("%s\n",(fl?"no":"yes"));
    }
}

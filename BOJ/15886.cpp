#include<bits/stdc++.h>
using namespace std;
char s[1010];
int cnt;
int main(){
    scanf("%*d %s",s);
    for(int i=0;s[i];i++) if(s[i]=='E' && s[i+1]=='W') cnt++;
    printf("%d",cnt);
}
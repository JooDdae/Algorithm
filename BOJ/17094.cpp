#include<bits/stdc++.h>
using namespace std;
char s[101010];
int chk[256];
int main(){
    scanf("%*d %s",s);
    for(int i=0;s[i];i++) chk[s[i]]++;
    printf("%s",chk['2']==chk['e']?"yee":chk['2']>chk['e']?"2":"e");
}
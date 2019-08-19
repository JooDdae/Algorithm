#include<bits/stdc++.h>
using namespace std;
char s[20],chk[256];
int main(){
    scanf("%*d %s",s);
    for(int i=0;s[i];i++) chk[s[i]]++;
    printf("%s",chk['A']==chk['B']?"Tie":chk['A']>chk['B']?"A":"B");
}
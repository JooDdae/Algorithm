#include<bits/stdc++.h>
using namespace std;
char s[10101];
int fl,ans;
int main(){
    scanf("%*d %s",s);
    for(int i=0;s[i];i++){
    	if(s[i] == 'O') ans += i + ++fl;
    	else fl=0;
    }
    printf("%d",ans);
}